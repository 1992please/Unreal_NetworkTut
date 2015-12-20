// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Network.h"
#include "NetworkGameMode.h"
#include "NetworkCharacter.h"

ANetworkGameMode::ANetworkGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
