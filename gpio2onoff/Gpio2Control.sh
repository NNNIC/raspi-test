#!/bin/sh
echo : shell start !!

curfunc=""
nextfunc=""

callstack=()

#[SYN-G-GEN OUTPUT START] $/./$
    #             psggConverterLib.dll converted from psgg-file:Gpio2Control.psgg

    #   E_0001
    declare -i i=0
    #   S_END
    S_END()
    {
        echo .
    }
    #   S_EXPORT_GPIO2
    S_EXPORT_GPIO2()
    {
        if [ $1 -eq 1 ]; then
            echo 2 > /sys/class/gpio/export
            sleepenh 1
            echo out > /sys/class/gpio/gpio2/direction
        fi
        #    SetNextStateIf
            if [ "$nextfunc" = "" ]; then
                nextfunc="S_SLEEP"
            fi
    }
    #   S_HELLOWORLD
    S_HELLOWORLD()
    {
        if [ $1 -eq 1 ]; then
            echo Hello World!
        fi
        #    SetNextStateIf
            if [ "$nextfunc" = "" ]; then
                nextfunc="S_EXPORT_GPIO2"
            fi
    }
    #   S_LOP000
    S_LOP000()
    {
        i = 0
        #   Goto
            nextfunc="S_LOP000_LoopCheckAndGosub____"
    }
    S_LOP000_LoopCheckAndGosub____()
    {
        if [ $i -lt 10 ]; then
            callstack+=("S_LOP000_LoopNext____")
            nextfunc="S_SBS000"
        else
            #   Goto
                nextfunc="S_SLEEP3"
        fi
    }
    S_LOP000_LoopNext____()
    {
        i=$i+1
        #   Goto
            nextfunc="S_LOP000_LoopCheckAndGosub____"
    }
    #   S_OFF
    S_OFF()
    {
        if [ $1 -eq 1 ]; then
            echo 0 > /sys/class/gpio/gpio2/value
        fi
        #    SetNextStateIf
            if [ "$nextfunc" = "" ]; then
                nextfunc="S_RET000"
            fi
    }
    #   S_ON
    S_ON()
    {
        if [ $1 -eq 1 ]; then
            echo 1 > /sys/class/gpio/gpio2/value
        fi
        #    SetNextStateIf
            if [ "$nextfunc" = "" ]; then
                nextfunc="S_SLEEP1"
            fi
    }
    #   S_RET000
    S_RET000()
    {
        declare -i num=${#callstack[@]}-1
        nextfunc=${callstack[num]}
        callstack=("${callstack[@]:0:$num}")
    }
    #   S_SBS000
    S_SBS000()
    {
        #   Goto
            nextfunc="S_SLEEP2"
    }
    #   S_SLEEP
    S_SLEEP()
    {
        if [ $1 -eq 1 ]; then
            sleepenh 1
        fi
        #    SetNextStateIf
            if [ "$nextfunc" = "" ]; then
                nextfunc="S_LOP000"
            fi
    }
    #   S_SLEEP1
    S_SLEEP1()
    {
        if [ $1 -eq 1 ]; then
            sleepenh 1
        fi
        #    SetNextStateIf
            if [ "$nextfunc" = "" ]; then
                nextfunc="S_OFF"
            fi
    }
    #   S_SLEEP2
    S_SLEEP2()
    {
        if [ $1 -eq 1 ]; then
            sleepenh 1
        fi
        #    SetNextStateIf
            if [ "$nextfunc" = "" ]; then
                nextfunc="S_ON"
            fi
    }
    #   S_SLEEP3
    S_SLEEP3()
    {
        if [ $1 -eq 1 ]; then
            sleepenh 1
        fi
        #    SetNextStateIf
            if [ "$nextfunc" = "" ]; then
                nextfunc="S_UNEXPORT_GPIO2"
            fi
    }
    #   S_START
    S_START()
    {
        #   Goto
            nextfunc="S_HELLOWORLD"
    }
    #   S_UNEXPORT_GPIO2
    S_UNEXPORT_GPIO2()
    {
        if [ $1 -eq 1 ]; then
            echo 2 > /sys/class/gpio/unexport
        fi
        #    SetNextStateIf
            if [ "$nextfunc" = "" ]; then
                nextfunc="S_END"
            fi
    }


#[SYN-G-GEN OUTPUT END]

nextfunc="S_START"

echo : request $nextfunc

declare -i _loop=0
max=1000
while  [ $_loop -le $max ]; do
    #echo :  w $nextfunc
    #echo : running $curfunc
    bFirst=0
    if [ "$nextfunc" != "" ]; then
        curfunc=$nextfunc
        nextfunc=""
        bFirst=1
    fi

    #[SYN-G-GEN OUTPUT START] $/^S/->#callfunc$
    #             psggConverterLib.dll converted from psgg-file:Gpio2Control.psgg

    if [ "$curfunc" = "S_END" ]; then
        S_END $bFirst
    fi
    if [ "$curfunc" = "S_EXPORT_GPIO2" ]; then
        S_EXPORT_GPIO2 $bFirst
    fi
    if [ "$curfunc" = "S_HELLOWORLD" ]; then
        S_HELLOWORLD $bFirst
    fi
    if [ "$curfunc" = "S_LOP000" ]; then
        S_LOP000 $bFirst
    fi
    if [ "$curfunc" = "S_LOP000_LoopCheckAndGosub____" ]; then
        S_LOP000_LoopCheckAndGosub____ $bFirst
    fi
    if [ "$curfunc" = "S_LOP000_LoopNext____" ]; then
        S_LOP000_LoopNext____ $bFirst
    fi
    if [ "$curfunc" = "S_OFF" ]; then
        S_OFF $bFirst
    fi
    if [ "$curfunc" = "S_ON" ]; then
        S_ON $bFirst
    fi
    if [ "$curfunc" = "S_RET000" ]; then
        S_RET000 $bFirst
    fi
    if [ "$curfunc" = "S_SBS000" ]; then
        S_SBS000 $bFirst
    fi
    if [ "$curfunc" = "S_SLEEP" ]; then
        S_SLEEP $bFirst
    fi
    if [ "$curfunc" = "S_SLEEP1" ]; then
        S_SLEEP1 $bFirst
    fi
    if [ "$curfunc" = "S_SLEEP2" ]; then
        S_SLEEP2 $bFirst
    fi
    if [ "$curfunc" = "S_SLEEP3" ]; then
        S_SLEEP3 $bFirst
    fi
    if [ "$curfunc" = "S_START" ]; then
        S_START $bFirst
    fi
    if [ "$curfunc" = "S_UNEXPORT_GPIO2" ]; then
        S_UNEXPORT_GPIO2 $bFirst
    fi


    #[SYN-G-GEN OUTPUT END]

    if [ "$curfunc" = "S_END" ]; then
        break
    fi
    #echo : loop
    #read a
    _loop=$_loop+1
done

echo : shell end!


<< COMMENTOUT

:::: PSGG MACRO ::::
:psgg-macro-start

; commentline format  {%0} will be replaced to a comment.
commentline=                                                    # {%0}

@branch=@@@
<<<?"{%0}"/^brif$/
if [[brcond:{%N}]]; then
    $macro:SetNextState({%1})$ 
fi
>>>
<<<?"{%0}"/^brifc$/
if [[brcond:{%N}]]; then
    $macro:SetNextState({%1})$ 
>>>
<<<?"{%0}"/^brelseif$/
elif [[brcond:{%N}]]; then
    $macro:SetNextState({%1})$ 
fi
>>>
<<<?"{%0}"/^brelseifc$/
elif [[brcond:{%N}]]; then
    $macro:SetNextState({%1})$
>>>
<<<?"{%0}"/^brelse$/
else 
    $macro:SetNextState({%1})$
fi
>>>
<<<?"{%0}"/^br_/
$macro:{%0}({%1})$
>>>
@@@

#callfunc=@@@
if [ "$curfunc" = "[[state]]" ]; then
    [[state]] $bFirst
fi
<<<?state-typ/^loop$/
if [ "$curfunc" = "[[state]]_LoopCheckAndGosub____" ]; then
    [[state]]_LoopCheckAndGosub____ $bFirst
fi
if [ "$curfunc" = "[[state]]_LoopNext____" ]; then
    [[state]]_LoopNext____ $bFirst
fi
eof>>>
@@@

SetNextState=@@@
#    SetNextState
    nextfunc="{%1}"
@@@

SetNextStateIf=@@@
#    SetNextStateIf
    if [ "$nextfunc" = "" ]; then 
        nextfunc="{%1}"
    fi 
@@@

Goto=@@@
#   Goto
    nextfunc="{%1}"
@@@

Gosub=@@@
callstack+=("{%2}")
nextfunc="{%1}"
@@@

Return=@@@
declare -i num=${#callstack[@]}-1
nextfunc=${callstack[num]}
callstack=("${callstack[@]:0:$num}")
@@@

:psgg-macro-end
COMMENTOUT
