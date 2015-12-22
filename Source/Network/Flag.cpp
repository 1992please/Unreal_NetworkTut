// Fill out your copyright notice in the Description page of Project Settings.

#include "Network.h"
#include "Flag.h"
#include "NetworkGameMode.h"

// Sets default values
AFlag::AFlag()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(60.0f);
	RootComponent = CollisionComp;
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &AFlag::OnOverlapBegin);
	bReplicates = true;
}

// Called when the game starts or when spawned
void AFlag::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFlag::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AFlag::OnOverlapBegin(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Role == ROLE_Authority)
	{
		UpdateScore(5);
		Destroy();
	}
}

void AFlag::UpdateScore_Implementation(int32 Amount)
{
	// Get game mode and cast it to our game mode.
	ANetworkGameMode* GameMode = Cast<ANetworkGameMode>(GetWorld()->GetAuthGameMode());
	//Add Score
	GameMode->AddScore(Amount);
}

bool AFlag::UpdateScore_Validate(int32 Amout)
{
	return true;
}