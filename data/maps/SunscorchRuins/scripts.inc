
SunscorchRuins_MapScripts::
    .byte 0

@ ===== AEVUM SUNSCORCH FOSSILS BEGIN =====
SunscorchRuins_EventScript_ClawFossil::
    lockall
    goto_if_set FLAG_AEVUM_RECEIVED_CLAW_FOSSIL, SunscorchRuins_EventScript_FossilAlreadyTaken
    checkitemspace ITEM_CLAW_FOSSIL
    goto_if_eq VAR_RESULT, FALSE, SunscorchRuins_EventScript_FossilBagFull
    giveitem ITEM_CLAW_FOSSIL
    goto_if_eq VAR_RESULT, FALSE, SunscorchRuins_EventScript_FossilBagFull
    setflag FLAG_AEVUM_RECEIVED_CLAW_FOSSIL
    releaseall
    end

SunscorchRuins_EventScript_RootFossil::
    lockall
    goto_if_set FLAG_AEVUM_RECEIVED_ROOT_FOSSIL, SunscorchRuins_EventScript_FossilAlreadyTaken
    checkitemspace ITEM_ROOT_FOSSIL
    goto_if_eq VAR_RESULT, FALSE, SunscorchRuins_EventScript_FossilBagFull
    giveitem ITEM_ROOT_FOSSIL
    goto_if_eq VAR_RESULT, FALSE, SunscorchRuins_EventScript_FossilBagFull
    setflag FLAG_AEVUM_RECEIVED_ROOT_FOSSIL
    releaseall
    end

SunscorchRuins_EventScript_FossilAlreadyTaken::
    msgbox SunscorchRuins_Text_FossilAlreadyTaken, MSGBOX_DEFAULT
    releaseall
    end

SunscorchRuins_EventScript_FossilBagFull::
    msgbox SunscorchRuins_Text_FossilBagFull, MSGBOX_DEFAULT
    releaseall
    end

SunscorchRuins_Text_FossilAlreadyTaken:
    .string "The fossil deposit here has already been recovered.$"

SunscorchRuins_Text_FossilBagFull:
    .string "There is not enough room in your Bag for the fossil.$"
@ ===== AEVUM SUNSCORCH FOSSILS END =====
