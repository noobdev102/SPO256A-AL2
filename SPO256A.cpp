#include "Arduino.h"
#include "SPO256A.h"

#define NOP __asm__ __volatile__ ("nop\n\t")

// init the queue (constructor).
SPO256A::SPO256A(int ALD, int LRQ)
{
  pinMode(ALD, OUTPUT);
  digitalWrite(ALD, HIGH);
  pinMode(LRQ, INPUT);
  DDRD = B11111111;
  _ALD = ALD;
  _LRQ = LRQ;

  //init queue
  size = 0;       // set the size of queue to zero.
  items = 0;      // set the number of items of queue to zero.

  head = 0;       // set the head of the queue to zero.
  tail = 0;       // set the tail of the queue to zero.

  // allocate enough memory for the array.
  contents = (char *) malloc (sizeof (char) * initialSize);

  // if there is a memory allocation error.
  if (contents == NULL)
    exit ("QUEUE: insufficient memory to initialize queue.");

  // set the initial size of the queue.
  size = initialSize;
}

// clear the queue (destructor).
SPO256A::~SPO256A () {
  free (contents); // deallocate the array of the queue.

  contents = NULL; // set queue's array pointer to nowhere.

  size = 0;        // set the size of queue to zero.
  items = 0;       // set the number of items of queue to zero.

  head = 0;        // set the head of the queue to zero.
  tail = 0;        // set the tail of the queue to zero.
}

void SPO256A::SendToSPO256A(char phoneme){
  enqueue (phoneme);
}

// to be called from main loop
void SPO256A::HandleSPO256AQueue(void){
  if (isEmpty ()){
    return;
  }
  if (digitalRead(_LRQ) == LOW){
    PORTD = dequeue();
    digitalWrite(_ALD, LOW);  // toggle ALD line to load data
    NOP;                      // should be between 200 and 1100ns low according to specs
    NOP;                      // delay 62.5ns on a 16MHz AtMega
    NOP;
    NOP;
    //delay(1);               // 1 micro sec is way too much
    digitalWrite(_ALD, HIGH);
  }  
}

// resize the size of the queue.
void SPO256A::resize (const int s) {
  // defensive issue.
  if (s <= 0)
    exit ("QUEUE: error due to undesirable size for queue size.");

  // allocate enough memory for the temporary array.
  char * temp = (char *) malloc (sizeof (char) * s);

  // if there is a memory allocation error.
  if (temp == NULL)
    exit ("QUEUE: insufficient memory to initialize temporary queue.");

  // copy the items from the old queue to the new one.
  for (int i = 0; i < items; i++)
    temp[i] = contents[(head + i) % size];

  // deallocate the old array of the queue.
  free (contents);

  // copy the pointer of the new queue.
  contents = temp;

  // set the head and tail of the new queue.
  head = 0; tail = items;

  // set the new size of the queue.
  size = s;
}

// add an item to the queue.
void SPO256A::enqueue (const char i) {
  // check if the queue is full.
  if (isFull ())
    // double size of array.
    resize (size * 2);

  // store the item to the array.
  contents[tail++] = i;

  // wrap-around index.
  if (tail == size) tail = 0;

  // increase the items.
  items++;
}

// remove an item from the queue.
char SPO256A::dequeue () {
  // check if the queue is empty.
  if (isEmpty ())
    exit ("QUEUE: can't pop item from queue: queue is empty.");

  // fetch the item from the array.
  char item = contents[head++];

  // decrease the items.
  items--;

  // wrap-around index.
  if (head == size) head = 0;

  // shrink size of array if necessary.
  if (!isEmpty () && (items <= size / 4))
    resize (size / 2);

  // return the item from the array.
  return item;
}

// check if the queue is empty.
bool SPO256A::isEmpty () const {
  return items == 0;
}

// check if the queue is full.
bool SPO256A::isFull () const {
  return items == size;
}

// exit report method in case of error.
void SPO256A::exit (const char * m) const {
  //println (m); // debug output
  // loop blinking until hardware reset.
  blink ();
}

// led blinking method in case of error.
void SPO256A::blink () const {
  // set led pin as output.
  pinMode (ledPin, OUTPUT);

  // continue looping until hardware reset.
  while (true) {
    digitalWrite (ledPin, HIGH); // sets the LED on.
    delay (250);                 // pauses 1/4 of second.
    digitalWrite (ledPin, LOW);  // sets the LED off.
    delay (250);                 // pauses 1/4 of second.
  }

  // solution selected due to lack of exit() and assert().
}

