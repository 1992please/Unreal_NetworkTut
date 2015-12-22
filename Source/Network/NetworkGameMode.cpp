// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Network.h"
#include "NetworkGameMode.h"
#include "NetworkCharacter.h"
#include "MyGameState.h"

ANetworkGameMode::ANetworkGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ANetworkGameMode::AddScore(int32 Amount)
{
	GetGameState<AMyGameState>()->Score += Amount;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FromInt(GetGameState<AMyGameState>()->Score));
}