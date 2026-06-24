// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BridgeLearningActor.generated.h"

UCLASS()
class CPPBRIDGELEARNING_API ABridgeLearningActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABridgeLearningActor();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BridgeLearning")
	int32 TestNumber;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
