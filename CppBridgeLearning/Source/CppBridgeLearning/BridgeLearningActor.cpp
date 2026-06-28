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

	ScoreArray.Add(10);
	ScoreArray.Add(20);
	ScoreArray.Add(30);

	for (int32 Score : ScoreArray)
	{
		UE_LOG(LogTemp, Warning, TEXT("Score = %d"), Score);
	}

	int32 MaxValue = MyMax(15, 25);
	UE_LOG(LogTemp, Warning, TEXT("MyMax Result = %d"), MaxValue);

	if (GEngine)
	{
		FString Message = FString::Printf(TEXT("ScoreArray Num = %d, MyMax = %d"), ScoreArray.Num(), MaxValue);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, Message);
	}

	ItemNameCache.Add(1, TEXT("book"));
	ItemNameCache.Add(1, TEXT("text"));
	
	FString* FoundPtr = ItemNameCache.Find(1);
	if (FoundPtr)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), **FoundPtr);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("NULL"));
	}
	FString& Ref = ItemNameCache.FindOrAdd(2);
	Ref = TEXT("Something");
	FString* FoundPtr2 = ItemNameCache.Find(2);
	if (FoundPtr2)
	{
		UE_LOG(LogTemp, Warning, TEXT("After FindOrAdd: %s"), **FoundPtr2);
	}
}

// Called every frame
void ABridgeLearningActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}