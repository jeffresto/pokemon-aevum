
MourningvaleCovenantShrine_MapScripts::
    .byte 0

@ ===== AEVUM SPIRITOMB STATIC BEGIN =====
MourningvaleCovenantShrine_EventScript_Spiritomb::
    lockall
    goto_if_set FLAG_AEVUM_CAUGHT_SPIRITOMB, MourningvaleCovenantShrine_EventScript_ShrineDormant
    checkitem ITEM_ODD_KEYSTONE
    goto_if_eq VAR_RESULT, FALSE, MourningvaleCovenantShrine_EventScript_NeedKeystone
    msgbox MourningvaleCovenantShrine_Text_UseKeystone, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, MourningvaleCovenantShrine_EventScript_Cancel
    setwildbattle SPECIES_SPIRITOMB, 40, ITEM_NONE
    dowildbattle
    specialvar VAR_RESULT, GetBattleOutcome
    goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, MourningvaleCovenantShrine_EventScript_SpiritombCaught
    msgbox MourningvaleCovenantShrine_Text_SpiritombRetry, MSGBOX_DEFAULT
    releaseall
    end

MourningvaleCovenantShrine_EventScript_SpiritombCaught::
    removeitem ITEM_ODD_KEYSTONE
    setflag FLAG_AEVUM_CAUGHT_SPIRITOMB
    msgbox MourningvaleCovenantShrine_Text_SpiritombCaught, MSGBOX_DEFAULT
    releaseall
    end

MourningvaleCovenantShrine_EventScript_NeedKeystone::
    msgbox MourningvaleCovenantShrine_Text_NeedKeystone, MSGBOX_DEFAULT
    releaseall
    end

MourningvaleCovenantShrine_EventScript_ShrineDormant::
    msgbox MourningvaleCovenantShrine_Text_ShrineDormant, MSGBOX_DEFAULT
    releaseall
    end

MourningvaleCovenantShrine_EventScript_Cancel::
    releaseall
    end

MourningvaleCovenantShrine_Text_UseKeystone:
    .string "The ODD KEYSTONE reacts to the Covenant shrine. Place it?$"

MourningvaleCovenantShrine_Text_NeedKeystone:
    .string "A circular recess in the shrine is missing a keystone.$"

MourningvaleCovenantShrine_Text_SpiritombRetry:
    .string "The shrine fell silent, but the keystone still reacts.$"

MourningvaleCovenantShrine_Text_SpiritombCaught:
    .string "The energy sealed within the shrine has been released.$"

MourningvaleCovenantShrine_Text_ShrineDormant:
    .string "The old Covenant shrine is dormant.$"
@ ===== AEVUM SPIRITOMB STATIC END =====
