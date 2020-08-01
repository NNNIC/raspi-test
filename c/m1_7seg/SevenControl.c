#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//== Declear States  ==

//                                      [STATEGO OUTPUT START] $/^S_/->#static$
    //             psggConverterLib.dll converted from psgg-file:SevenControl.psgg

    static void S_ALL_OFF(bool bFirst);
    static void S_ALL_OFF1(bool bFirst);
    static void S_ALL_ON2(bool bFirst);
    static void S_EIGHT(bool bFirst);
    static void S_END(bool bFirst);
    static void S_FIVE(bool bFirst);
    static void S_FOUR(bool bFirst);
    static void S_LOP000(bool bFirst);
    static void S_LOP000_LoopCheckAndGosub____(bool bFirst);
    static void S_LOP000_LoopCheckAndGosub____(bool bFirst);
    static void S_LOP000_LoopNext____(bool bFirst);
    static void S_NINE(bool bFirst);
    static void S_ONE(bool bFirst);
    static void S_RET000(bool bFirst);
    static void S_SBS000(bool bFirst);
    static void S_SEVEN(bool bFirst);
    static void S_SIX(bool bFirst);
    static void S_START(bool bFirst);
    static void S_START1(bool bFirst);
    static void S_THREE(bool bFirst);
    static void S_TWO(bool bFirst);
    static void S_WAIT_500_2(bool bFirst);
    static void S_ZERO(bool bFirst);


//                                      [STATEGO OUTPUT END]

// == manager ==

static void *m_curfunc = NULL;
static void *m_nextfunc= NULL;
static bool  m_bNoWait = false;

const int MAX_CALL_STACK = 10;
static void *m_callstack[10];
static int   m_callstack_level = 0;

static void update() {
    while(true) {
        bool bFirst = false;
        if (m_nextfunc!=NULL) {
            m_curfunc = m_nextfunc;
            m_nextfunc = NULL;
            bFirst = true;
        }

        m_bNoWait = false;
        if (m_curfunc!=NULL) {
            void (*func)(bool);
            func = m_curfunc;
            (*func)(bFirst);
        }
        if (m_bNoWait == false) break;
    }
}

static void Goto(void *st) {
    m_nextfunc = st;
}

static bool CheckState(void *st) {
    return m_curfunc == st;
}

static bool HasNextState() {
    return m_nextfunc != NULL;
}

static void NoWait()
{
    m_bNoWait = true;
}

static void GoSubState(void *sub, void *next)
{
	if (m_callstack_level >= MAX_CALL_STACK-1) 
	{
		printf("CALL STACK OVER FLOW\n");
		exit(1);
	}
	m_callstack[m_callstack_level++] = next;
	Goto(sub);
}

static void ReturnState()
{
	void *st = NULL;

	if (m_callstack_level <= 0)
	{
		printf("CALL STACK UNDER FLOW\n");
		exit(1);
	}
	m_callstack_level--;
	st = m_callstack[m_callstack_level];
	
	Goto(st);
}
//                                      [STATEGO OUTPUT START] $/^E_/$
    //             psggConverterLib.dll converted from psgg-file:SevenControl.psgg

    /*
        E_0000
    */
    static int m_i = 0;
    /*
        E_0002
    */
    #define PIN_T   27
    #define PIN_UR  22
    #define PIN_C   4
    #define PIN_DR  18
    #define PIN_P   23
    #define PIN_B   15
    #define PIN_DL  14
    #define PIN_UL  17


//                                      [STATEGO OUTPUT END] 

//                                      [STATEGO OUTPUT START] $/^S_/$
    //             psggConverterLib.dll converted from psgg-file:SevenControl.psgg

    /*
        S_ALL_OFF
    */
    void S_ALL_OFF(bool bFirst)
    {
        digitalWrite(PIN_T, LOW );
        digitalWrite(PIN_UR, LOW );
        digitalWrite(PIN_C, LOW );
        digitalWrite(PIN_DR, LOW );
        digitalWrite(PIN_P, LOW );
        digitalWrite(PIN_B, LOW );
        digitalWrite(PIN_DL, LOW );
        digitalWrite(PIN_UL, LOW );
        if (!HasNextState())
        {
            Goto(S_RET000);
        }
    }
    /*
        S_ALL_OFF1
    */
    void S_ALL_OFF1(bool bFirst)
    {
        digitalWrite(PIN_T, LOW );
        digitalWrite(PIN_UR, LOW );
        digitalWrite(PIN_C, LOW );
        digitalWrite(PIN_DR, LOW );
        digitalWrite(PIN_P, LOW );
        digitalWrite(PIN_B, LOW );
        digitalWrite(PIN_DL, LOW );
        digitalWrite(PIN_UL, LOW );
        if (!HasNextState())
        {
            Goto(S_LOP000);
        }
    }
    /*
        S_ALL_ON2
    */
    void S_ALL_ON2(bool bFirst)
    {
        int a = m_i % 10;
        if (a == 0) { Goto( S_ZERO ); }
        else if (a == 1) { Goto( S_ONE ); }
        else if (a == 2) { Goto( S_TWO ); }
        else if (a == 3) { Goto( S_THREE ); }
        else if (a == 4) { Goto( S_FOUR ); }
        else if (a == 5) { Goto( S_FIVE ); }
        else if (a == 6) { Goto( S_SIX ); }
        else if (a == 7) { Goto( S_SEVEN ); }
        else if (a == 8) { Goto( S_EIGHT ); }
        else { Goto( S_NINE ); }
    }
    /*
        S_EIGHT
    */
    void S_EIGHT(bool bFirst)
    {
        digitalWrite(PIN_T,  HIGH);
        digitalWrite(PIN_UR,  HIGH);
        digitalWrite(PIN_C,  HIGH);
        digitalWrite(PIN_DR,  HIGH);
        digitalWrite(PIN_B,  HIGH);
        digitalWrite(PIN_DL,  HIGH);
        digitalWrite(PIN_UL,  HIGH);
        if (!HasNextState())
        {
            Goto(S_WAIT_500_2);
        }
    }
    /*
        S_END
    */
    void S_END(bool bFirst)
    {
    }
    /*
        S_FIVE
    */
    void S_FIVE(bool bFirst)
    {
        digitalWrite(PIN_T,  HIGH);
        digitalWrite(PIN_C,  HIGH);
        digitalWrite(PIN_DR,  HIGH);
        digitalWrite(PIN_B,  HIGH);
        digitalWrite(PIN_UL,  HIGH);
        if (!HasNextState())
        {
            Goto(S_WAIT_500_2);
        }
    }
    /*
        S_FOUR
    */
    void S_FOUR(bool bFirst)
    {
        digitalWrite(PIN_UR,  HIGH);
        digitalWrite(PIN_C,  HIGH);
        digitalWrite(PIN_DR,  HIGH);
        digitalWrite(PIN_UL,  HIGH);
        if (!HasNextState())
        {
            Goto(S_WAIT_500_2);
        }
    }
    /*
        S_LOP000
    */
    void S_LOP000(bool bFirst)
    {
        m_i = 0;
        Goto(S_LOP000_LoopCheckAndGosub____);
        NoWait();
    }
    void S_LOP000_LoopCheckAndGosub____(bool bFirst)
    {
        if (m_i < 1000) GoSubState(S_SBS000,S_LOP000_LoopNext____);
        else               Goto(S_END);
        NoWait();
    }
    void S_LOP000_LoopNext____(bool bFirst)
    {
        m_i++;
        Goto(S_LOP000_LoopCheckAndGosub____);
        NoWait();
    }
    /*
        S_NINE
    */
    void S_NINE(bool bFirst)
    {
        digitalWrite(PIN_T,  HIGH);
        digitalWrite(PIN_UR,  HIGH);
        digitalWrite(PIN_C,  HIGH);
        digitalWrite(PIN_DR,  HIGH);
        digitalWrite(PIN_UL,  HIGH);
        if (!HasNextState())
        {
            Goto(S_WAIT_500_2);
        }
    }
    /*
        S_ONE
    */
    void S_ONE(bool bFirst)
    {
        digitalWrite(PIN_UR,  HIGH);
        digitalWrite(PIN_DR,  HIGH);
        if (!HasNextState())
        {
            Goto(S_WAIT_500_2);
        }
    }
    /*
        S_RET000
    */
    void S_RET000(bool bFirst)
    {
        ReturnState();
        NoWait();
    }
    /*
        S_SBS000
    */
    void S_SBS000(bool bFirst)
    {
        if (!HasNextState())
        {
            Goto(S_ALL_ON2);
        }
    }
    /*
        S_SEVEN
    */
    void S_SEVEN(bool bFirst)
    {
        digitalWrite(PIN_T,  HIGH);
        digitalWrite(PIN_UR,  HIGH);
        digitalWrite(PIN_DR,  HIGH);
        digitalWrite(PIN_UL,  HIGH);
        if (!HasNextState())
        {
            Goto(S_WAIT_500_2);
        }
    }
    /*
        S_SIX
    */
    void S_SIX(bool bFirst)
    {
        digitalWrite(PIN_T,  HIGH);
        digitalWrite(PIN_C,  HIGH);
        digitalWrite(PIN_DR,  HIGH);
        digitalWrite(PIN_B,  HIGH);
        digitalWrite(PIN_DL,  HIGH);
        digitalWrite(PIN_UL,  HIGH);
        if (!HasNextState())
        {
            Goto(S_WAIT_500_2);
        }
    }
    /*
        S_START
    */
    void S_START(bool bFirst)
    {
        Goto(S_START1);
        NoWait();
    }
    /*
        S_START1
    */
    void S_START1(bool bFirst)
    {
        if (bFirst)
        {
            wiringPiSetupGpio();
            pinMode (PIN_T,  OUTPUT) ;
            pinMode (PIN_UR, OUTPUT) ;
            pinMode (PIN_C,  OUTPUT) ;
            pinMode (PIN_DR, OUTPUT) ;
            pinMode (PIN_P,  OUTPUT) ;
            pinMode (PIN_B,  OUTPUT) ;
            pinMode (PIN_DL, OUTPUT) ;
            pinMode (PIN_UL, OUTPUT) ;
        }
        if (!HasNextState())
        {
            Goto(S_ALL_OFF1);
        }
    }
    /*
        S_THREE
    */
    void S_THREE(bool bFirst)
    {
        digitalWrite(PIN_T,  HIGH);
        digitalWrite(PIN_UR,  HIGH);
        digitalWrite(PIN_C,  HIGH);
        digitalWrite(PIN_DR,  HIGH);
        digitalWrite(PIN_B,  HIGH);
        if (!HasNextState())
        {
            Goto(S_WAIT_500_2);
        }
    }
    /*
        S_TWO
    */
    void S_TWO(bool bFirst)
    {
        digitalWrite(PIN_T,  HIGH);
        digitalWrite(PIN_UR,  HIGH);
        digitalWrite(PIN_C,  HIGH);
        digitalWrite(PIN_B,  HIGH);
        digitalWrite(PIN_DL,  HIGH);
        if (!HasNextState())
        {
            Goto(S_WAIT_500_2);
        }
    }
    /*
        S_WAIT_500_2
    */
    void S_WAIT_500_2(bool bFirst)
    {
        if (bFirst)
        {
            delay(500);
        }
        if (!HasNextState())
        {
            Goto(S_ALL_OFF);
        }
    }
    /*
        S_ZERO
    */
    void S_ZERO(bool bFirst)
    {
        digitalWrite(PIN_T,  HIGH);
        digitalWrite(PIN_UR,  HIGH);
        digitalWrite(PIN_DR,  HIGH);
        digitalWrite(PIN_B,  HIGH);
        digitalWrite(PIN_DL,  HIGH);
        digitalWrite(PIN_UL,  HIGH);
        if (!HasNextState())
        {
            Goto(S_WAIT_500_2);
        }
    }


//                                      [STATEGO OUTPUT END]

// externs
extern void SevenControl_start()
{
    Goto(S_START);
}
extern void SevenControl_update()
{
    update();
}
extern bool SevenControl_is_end()
{
    return CheckState(S_END);
}

/*
:psgg-macro-start

@on=digitalWrite(PIN_{%0},  HIGH); 
@off=digitalWrite(PIN_{%0}, LOW ); 

:psgg-macro-end
*/