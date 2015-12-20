// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Flag.generated.h"

UCLASS()
class NETWORK_API AFlag : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFlag();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Our sphere component for collision
	USphereComponent* CollisionComp;
	
	// Collision Function!
	UFUNCTION()
	void OnOverlapBegin(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// Our server function to update the score
	UFUNCTION(Reliable, Server, WithValidation)
	void UpdateScore(int32 Amout);
	void UpdateScore_Implementation(int32 Amout);
	bool UpdateScore_Validate(int32 Amout);
};
