// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BridgeLearningActor.generated.h"

template<typename T>
T MyMax(T A, T B)
{
	return (A > B) ? A : B;
}
UCLASS()
class CPPBRIDGELEARNING_API ABridgeLearningActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABridgeLearningActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BridgeLearning")
	TArray<int32> ScoreArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int32, FString> ItemNameCache;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
