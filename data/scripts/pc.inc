EventScript_PC::
	lockall
	setvar VAR_0x8004, PC_LOCATION_OTHER
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox Text_BootUpPC, MSGBOX_DEFAULT
	goto EventScript_PCMainMenu
	end

EventScript_PCMainMenu::
        setvar VAR_0x8006, 0
        message gText_WhichPCShouldBeAccessed
        waitmessage
        special ScriptMenu_CreatePCMultichoice
        goto EventScript_AccessPC
        end

EventScript_AccessPC::
        switch VAR_RESULT
        case 0, EventScript_AccessPokemonStorage
        case 1, EventScript_AevumMoveManagement
        case 2, EventScript_TurnOffPC
        case MULTI_B_PRESSED, EventScript_TurnOffPC
        end

EventScript_AccessPlayersPC::
	playse SE_PC_LOGIN
	msgbox gText_AccessedPlayersPC, MSGBOX_DEFAULT
	special PlayerPC
	goto EventScript_PCMainMenu
	end

EventScript_AccessPokemonStorage::
        playse SE_PC_LOGIN
        msgbox gText_StorageSystemOpened, MSGBOX_DEFAULT
        special ShowPokemonStorageSystemPC
        goto EventScript_PCMainMenu
        end

EventScript_AccessSomeonesPC::
	msgbox gText_AccessedSomeonesPC, MSGBOX_DEFAULT
	return

EventScript_AccessLanettesPC::
#if IS_FRLG
	msgbox gText_AccessedBillsPC, MSGBOX_DEFAULT
#else
	msgbox gText_AccessedLanettesPC, MSGBOX_DEFAULT
#endif
	return

EventScript_AevumMoveManagement::
        setvar VAR_0x8006, 1
        message Aevum_Text_MoveManagement
        waitmessage
        special ScriptMenu_CreatePCMultichoice
        switch VAR_RESULT
        case 0, EventScript_AevumRelearnMove
        case 1, EventScript_AevumForgetMove
        case 2, EventScript_PCMainMenu
        case MULTI_B_PRESSED, EventScript_PCMainMenu
        end

EventScript_AevumRelearnMove::
        msgbox Aevum_Text_ChoosePokemon, MSGBOX_DEFAULT
        setmoverelearnerstate MOVE_RELEARNER_LEVEL_UP_MOVES
        special ChoosePartyMon
        goto_if_ge VAR_0x8004, PARTY_SIZE, EventScript_AevumMoveManagement
        special IsSelectedMonEgg
        goto_if_eq VAR_RESULT, TRUE, EventScript_AevumRelearnEgg
        special Special_HasMoveToRelearn
        goto_if_eq VAR_RESULT, FALSE, EventScript_AevumNoMovesToRelearn
        msgbox Aevum_Text_ChooseMoveToRelearn, MSGBOX_DEFAULT
        special TeachMoveRelearnerMove
        goto EventScript_AevumMoveManagement
        end

EventScript_AevumRelearnEgg::
        msgbox Aevum_Text_EggCannotManageMoves, MSGBOX_DEFAULT
        goto EventScript_AevumMoveManagement
        end

EventScript_AevumNoMovesToRelearn::
        msgbox Aevum_Text_NoMovesToRelearn, MSGBOX_DEFAULT
        goto EventScript_AevumMoveManagement
        end

EventScript_AevumForgetMove::
        msgbox Aevum_Text_ChoosePokemon, MSGBOX_DEFAULT
        special ChoosePartyMon
        goto_if_ge VAR_0x8004, PARTY_SIZE, EventScript_AevumMoveManagement
        special IsSelectedMonEgg
        goto_if_eq VAR_RESULT, TRUE, EventScript_AevumForgetEgg
        special GetNumMovesSelectedMonHas
        goto_if_eq VAR_RESULT, 1, EventScript_AevumCannotForgetOnlyMove
        msgbox Aevum_Text_ChooseMoveToForget, MSGBOX_DEFAULT
        fadescreen FADE_TO_BLACK
        special MoveDeleterChooseMoveToForget
        fadescreen FADE_FROM_BLACK
        goto_if_eq VAR_0x8005, MAX_MON_MOVES, EventScript_AevumMoveManagement
        special BufferMoveDeleterNicknameAndMove
        msgbox Aevum_Text_ConfirmForgetMove, MSGBOX_YESNO
        goto_if_eq VAR_RESULT, NO, EventScript_AevumMoveManagement
        special MoveDeleterForgetMove
        playfanfare MUS_MOVE_DELETED
        waitfanfare
        msgbox Aevum_Text_MoveForgotten, MSGBOX_DEFAULT
        goto EventScript_AevumMoveManagement
        end

EventScript_AevumForgetEgg::
        msgbox Aevum_Text_EggCannotManageMoves, MSGBOX_DEFAULT
        goto EventScript_AevumMoveManagement
        end

EventScript_AevumCannotForgetOnlyMove::
        msgbox Aevum_Text_CannotForgetOnlyMove, MSGBOX_DEFAULT
        goto EventScript_AevumMoveManagement
        end

Aevum_Text_MoveManagement::
        .string "MOVE MANAGEMENT$"

Aevum_Text_ChoosePokemon::
        .string "Choose a POKéMON.$"

Aevum_Text_ChooseMoveToRelearn::
        .string "Which move should be relearned?$"

Aevum_Text_ChooseMoveToForget::
        .string "Which move should be forgotten?$"

Aevum_Text_EggCannotManageMoves::
        .string "Moves can't be managed for an EGG.$"

Aevum_Text_NoMovesToRelearn::
        .string "This POKéMON has no moves to\n"
        .string "relearn right now.$"

Aevum_Text_CannotForgetOnlyMove::
        .string "A POKéMON can't forget its only\n"
        .string "move.$"

Aevum_Text_ConfirmForgetMove::
        .string "Forget {STR_VAR_2}?$"

Aevum_Text_MoveForgotten::
        .string "{STR_VAR_1} forgot {STR_VAR_2}.$"

EventScript_TurnOffPC::
	setvar VAR_0x8004, PC_LOCATION_OTHER
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

EventScript_AccessHallOfFame::
	goto_if_unset FLAG_SYS_GAME_CLEAR, EventScript_TurnOffPC
	playse SE_PC_LOGIN
	special AccessHallOfFamePC
	goto EventScript_AccessPC
	end

EventScript_AccessPokemonBoxLink::
	playse SE_PC_LOGIN
	msgbox gText_StorageSystemOpened, MSGBOX_DEFAULT
	special ShowPokemonStorageSystemPC
	goto EventScript_TurnOffPC
	end
