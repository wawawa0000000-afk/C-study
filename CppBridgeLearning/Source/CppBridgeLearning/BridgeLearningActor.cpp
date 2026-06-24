// Fill out your copyright notice in the Description page of Project Settings.

#include "BridgeLearningActor.h"

// Sets default values
ABridgeLearningActor::ABridgeLearningActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABridgeLearningActor::BeginPlay()
{
	Super::BeginPlay();

	ensure(TestNumber >= 0);

	if (GEngine)
	{
		FString Message = FString::Printf(TEXT("TestNumber = %d"), TestNumber);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, Message);
	}
}

// Called every frame
void ABridgeLearningActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}