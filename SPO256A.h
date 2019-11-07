
/* 
 *SPO256A.h Header file for the SPO256A library by noobdev102
 * thanks to Efstathios Chatzikyriakidis (contact@efxa.org) for QueueArray
 * starts blinking the led on queue error
 * tested with an uno
 * a1-a6 are connected to a0 - a5 for now
 * plan is to put a shift register in between 
 */

#ifndef SPO256A_h
#define SPO256A_h

#include "Arduino.h"

#define PA1 0x00
#define PA2 0x01
#define PA3 0x02
#define PA4 0x03
#define PA5 0x04
 
#define OY  0x05
#define AY  0x06
#define EH  0x07
#define KK3 0x08
#define PP  0x09
#define JH  0x0A
#define NN1 0x0B
#define IH  0x0C
#define TT2 0x0D
#define RR1 0x0E
#define AX  0x0F
#define MM  0x10
#define TT1 0x11
#define DH1 0x12
#define IY  0x13
#define EY  0x14
#define DD1 0x15
#define UW1 0x16
#define AO  0x17
#define AA  0x18
#define YY2 0x19
#define AE  0x1A
#define HH1 0x1B
#define BB1 0x1C
#define TH  0x1D
#define UH  0x1E
#define UW2 0x1F
#define AW  0x20
#define DD2 0x21
#define GG3 0x22
#define VV  0x23
#define GG1 0x24
#define SH  0x25
#define ZH  0x26
#define RR2 0x27
#define FF  0x28
#define KK2 0x29
#define KK1 0x2A
#define ZZ  0x2B
#define NG  0x2C
#define LL  0x2D
#define WW  0x2E
#define XR  0x2F
#define WH  0x30
#define YY1 0x31
#define CH  0x32
#define ER1 0x33
#define ER2 0x34
#define OW  0x35
#define DH2 0x36
#define SS  0x37
#define NN2 0x38
#define HH2 0x39
#define OR  0x3A
#define AR  0x3B
#define YR  0x3C
#define GG2 0x3D
#define EL  0x3E
#define BB2 0x3F
#define PE  0xFF

const byte s_monday[] PROGMEM = {MM,AX,AX,NN1,PA2,DD2,EY,PA5,PE};
const byte s_tuesday[] PROGMEM = {TT2,UW2,ZZ,PA2,DD2,EY,PA5,PE};
const byte s_wednesday[] PROGMEM = {WW,EH,EH,NN1,ZZ,PA2,DD2,EY,PA5,PE};
const byte s_thursday[] PROGMEM = {TH,ER2,ZZ,PA2,DD2,EY,PA5,PE};
const byte s_friday[] PROGMEM = {FF,RR2,AY,PA2,DD2,EY,PA5,PE};
const byte s_saturday[] PROGMEM = {SS,SS,AE,PA3,TT2,PA2,DD2,EY,PA5,PE};
const byte s_sunday[] PROGMEM = {SS,SS,AX,AX,NN1,PA2,PA2,DD2,EY,PA5,PE};
byte *const daysofweek[] PROGMEM = {s_monday, s_tuesday, s_wednesday, s_thursday, s_friday, s_saturday, s_sunday};

const byte s_january[] PROGMEM = {JH,AE,AE,NN1,YY2,XR,IY,PA5,PE};
const byte s_february[] PROGMEM = {FF,EH,EH,PA1,BB1,RR2,UW2,XR,IY,PA5,PE};
const byte s_march[] PROGMEM = {MM,AR,PA3,CH,PA5,PE};
const byte s_april[] PROGMEM = {EY,PA3,PP,RR2,IH,IH,LL,PA5,PE};
const byte s_may[] PROGMEM = {MM,EY,PA5,PE};
const byte s_june[] PROGMEM = {JH,UW2,NN1,PA5,PE};
const byte s_july[] PROGMEM = {JH,UW1,LL,AY,PA5,PE};
const byte s_august[] PROGMEM = {AO,AO,PA2,GG2,AX,SS,PA3,TT1,PA5,PE};
const byte s_september[] PROGMEM = {SS,SS,EH,PA3,PP,PA3,TT2,EH,EH,MM,PA1,BB2,ER1,PA5,PE};
const byte s_oktober[] PROGMEM = {AA,PA2,KK2,PA3,TT2,OW,PA1,BB2,ER1,PA5,PE};
const byte s_november[] PROGMEM = {NN2,OW,VV,EH,EH,MM,PA1,BB2,ER1,PA5,PE};
const byte s_december[] PROGMEM = {DD2,IY,SS,SS,EH,EH,MM,PA1,BB2,ER1,PA5,PE};
byte *const months[] PROGMEM = {s_january,s_february,s_march,s_april,s_may,s_june,s_july,s_august,s_september,s_oktober,s_november,s_december};

const byte s_zero[] PROGMEM = {ZZ,YR,OW,PA3,PE};
const byte s_one[] PROGMEM = {WW,AX,AX,NN1,PA3,PE};
const byte s_two[] PROGMEM = {TT2,UW2,PA3,PE};
const byte s_three[] PROGMEM = {TH,RR1,IY,PA3,PE};
const byte s_four[] PROGMEM = {FF,OR,PA3,PE};
const byte s_five[] PROGMEM = {FF,AY,VV,PA3,PE};
const byte s_six[] PROGMEM = {SS,SS,IH,IH,PA3,KK2,SS,PA3,PE};
const byte s_seven[] PROGMEM = {SS,SS,EH,EH,VV,IH,NN1,PA3,PE};
const byte s_eight[] PROGMEM = {EY,PA3,TT2,PA3,PE};
const byte s_nine[] PROGMEM = {NN1,AA,AY,NN1,PA3,PE};
const byte s_ten[] PROGMEM = {TT2,EH,EH,NN1,PA4,PE};
const byte s_eleven[] PROGMEM = {IH,LL,EH,EH,VV,IH,NN1,PA4,PE};
const byte s_twelve[] PROGMEM = {TT2,WH,EH,EH,LL,VV,PA4,PE};
const byte s_thirteen[] PROGMEM = {TH,ER1,PA2,PA3,TT2,IY,NN1,PA4,PE};
const byte s_fourteen[] PROGMEM = {FF,OR,PA2,PA3,TT2,IY,NN1,PA4,PE};
const byte s_fifteen[] PROGMEM = {FF,IH,FF,PA2,PA3,TT2,IY,NN1,PA4,PE};
const byte s_sixteen[] PROGMEM = {SS,SS,IH,PA3,KK2,SS,PA2,PA3,TT2,IY,NN1,PA4,PE};
const byte s_seventeen[] PROGMEM = {SS,SS,EH,VV,IH,NN1,PA2,PA3,TT2,IY,NN1,PA4,PE};
const byte s_eightteen[] PROGMEM = {EY,PA2,PA3,TT2,IY,NN1,PA4,PE};
const byte s_nineteen[] PROGMEM = {NN1,AY,NN1,PA2,PA3,TT2,IY,NN1,PA4,PE};
const byte s_twenty[] PROGMEM = {TT2,WH,EH,EH,NN1,PA2,PA3,TT2,IY,PA3,PE};
const byte s_thirty[] PROGMEM = {TH,ER2,PA2,PA3,TT2,IY,PA3,PE};
const byte s_fourty[] PROGMEM = {FF,OR,PA3,TT2,IY,PA4,PE};
const byte s_fifty[] PROGMEM = {FF,IH,FF,PA2,PA3,TT2,IY,PA4,PE};
const byte s_sixty[] PROGMEM = {SS,SS,IH,PA3,KK2,SS,PA2,PA3,TT2,IY,PA4,PE};
const byte s_seventy[] PROGMEM = {SS,SS,EH,VV,IH,NN1,PA2,PA3,TT2,IY,PA4,PE};
const byte s_eighty[] PROGMEM = {EY,PA3,TT2,IY,PA4,PE};
const byte s_ninety[] PROGMEM = {NN1,AY,NN1,PA3,TT2,IY,PA4,PE};
byte *const numbers[] PROGMEM = {s_zero,s_one,s_two,s_three,s_four,s_five,s_six,s_seven,s_eight,s_nine,
                                 s_ten,s_eleven,s_twelve,s_thirteen,s_fourteen,s_fifteen,s_sixteen,s_seventeen,s_eightteen,s_nineteen,
                                 s_twenty,s_thirty,s_fourty,s_fifty,s_sixty,s_seventy,s_eighty,s_ninety};

const byte s_hundred[] PROGMEM = {HH2,AX,AX,NN1,PA2,DD2,RR2,IH,IH,PA1,DD1,PA4,PE};
const byte s_thousand[] PROGMEM = {TH,AA,AW,ZZ,AE,NN1,DD1,PA4,PE};
const byte s_million[] PROGMEM = {MM,IH,IH,LL,YY1,AX,NN1,PA4,PE};
const byte s_billion[] PROGMEM = {BB2,IH,IH,LL,YY1,AX,NN1,PA4,PE};
byte *const largenumbers[] PROGMEM = {s_hundred,s_thousand,s_million,s_billion};


class SPO256A
{
  public:
      // init (constructor).
	SPO256A(int ALD, int LRQ);

    // clear (destructor).
    ~SPO256A();

    // queue phoneme
    void SendToSPO256A(char phoneme);

    // send queued phoneme to SPO256A when possible
    void HandleSPO256AQueue(void);

    // check if the queue is empty.
    bool isEmpty () const;

  private:

    int _ALD;
    int _LRQ;

    // add an item to the queue.
    void enqueue (const char i);

    // remove an item from the queue.
    char dequeue ();

    // get the number of items in the queue.
    int count () const;

    // check if the queue is full.
    bool isFull () const;

    // resize the size of the queue.
    void resize (const int s);

    // exit report method in case of error.
    void exit (const char * m) const;

    // led blinking method in case of error.
    void blink () const;

    // the initial size of the queue.
    static const int initialSize = 30;

    // the pin number of the on-board led.
    static const int ledPin = 13;

    char * contents;    // the array of the queue.

    int size;        // the size of the queue.
    int items;       // the number of items of the queue.

    int head;        // the head of the queue.
    int tail;        // the tail of the queue.
};
#endif //SPO256A_h
