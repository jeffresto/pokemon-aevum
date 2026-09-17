
VictoryRoadStarterSanctum_MapScripts::
    .byte 0

@ ===== AEVUM VICTORY ROAD STARTERS BEGIN =====
VictoryRoadStarterSanctum_EventScript_Treecko::
    lockall
    goto_if_eq VAR_STARTER_MON, 0, VictoryRoadStarterSanctum_EventScript_OriginalPartner
    goto_if_set FLAG_AEVUM_RECEIVED_VR_TREECKO, VictoryRoadStarterSanctum_EventScript_EmptyPedestal
    givemon SPECIES_TREECKO, 50
    goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, VictoryRoadStarterSanctum_EventScript_TreeckoReceived
    goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, VictoryRoadStarterSanctum_EventScript_TreeckoReceived
    goto Common_EventScript_NoMoreRoomForPokemon

VictoryRoadStarterSanctum_EventScript_TreeckoReceived::
    setflag FLAG_AEVUM_RECEIVED_VR_TREECKO
    msgbox VictoryRoadStarterSanctum_Text_StarterReceived, MSGBOX_DEFAULT
    releaseall
    end

VictoryRoadStarterSanctum_EventScript_Torchic::
    lockall
    goto_if_eq VAR_STARTER_MON, 1, VictoryRoadStarterSanctum_EventScript_OriginalPartner
    goto_if_set FLAG_AEVUM_RECEIVED_VR_TORCHIC, VictoryRoadStarterSanctum_EventScript_EmptyPedestal
    givemon SPECIES_TORCHIC, 50
    goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, VictoryRoadStarterSanctum_EventScript_TorchicReceived
    goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, VictoryRoadStarterSanctum_EventScript_TorchicReceived
    goto Common_EventScript_NoMoreRoomForPokemon

VictoryRoadStarterSanctum_EventScript_TorchicReceived::
    setflag FLAG_AEVUM_RECEIVED_VR_TORCHIC
    msgbox VictoryRoadStarterSanctum_Text_StarterReceived, MSGBOX_DEFAULT
    releaseall
    end

VictoryRoadStarterSanctum_EventScript_Mudkip::
    lockall
    goto_if_eq VAR_STARTER_MON, 2, VictoryRoadStarterSanctum_EventScript_OriginalPartner
    goto_if_set FLAG_AEVUM_RECEIVED_VR_MUDKIP, VictoryRoadStarterSanctum_EventScript_EmptyPedestal
    givemon SPECIES_MUDKIP, 50
    goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, VictoryRoadStarterSanctum_EventScript_MudkipReceived
    goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, VictoryRoadStarterSanctum_EventScript_MudkipReceived
    goto Common_EventScript_NoMoreRoomForPokemon

VictoryRoadStarterSanctum_EventScript_MudkipReceived::
    setflag FLAG_AEVUM_RECEIVED_VR_MUDKIP
    msgbox VictoryRoadStarterSanctum_Text_StarterReceived, MSGBOX_DEFAULT
    releaseall
    end

VictoryRoadStarterSanctum_EventScript_OriginalPartner::
    msgbox VictoryRoadStarterSanctum_Text_OriginalPartner, MSGBOX_DEFAULT
    releaseall
    end

VictoryRoadStarterSanctum_EventScript_EmptyPedestal::
    msgbox VictoryRoadStarterSanctum_Text_EmptyPedestal, MSGBOX_DEFAULT
    releaseall
    end

VictoryRoadStarterSanctum_Text_StarterReceived:
    .string "The Pokemon accepted you as its new partner.$"

VictoryRoadStarterSanctum_Text_OriginalPartner:
    .string "The pedestal reacts to the partner who began your journey.$"

VictoryRoadStarterSanctum_Text_EmptyPedestal:
    .string "The pedestal is empty now.$"
@ ===== AEVUM VICTORY ROAD STARTERS END =====
