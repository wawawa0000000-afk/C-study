// BridgeLearningActor.cpp
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

	// =====================================================
	// TArrayの基礎：Add / range-based for
	// =====================================================
	ScoreArray.Add(10);
	ScoreArray.Add(20);
	ScoreArray.Add(30);

	for (int32 Score : ScoreArray)
	{
		UE_LOG(LogTemp, Warning, TEXT("Score = %d"), Score);
	}

	// =====================================================
	// テンプレート関数の確認（MyMax）
	// =====================================================
	int32 MaxValue = MyMax(15, 25);
	UE_LOG(LogTemp, Warning, TEXT("MyMax Result = %d"), MaxValue);

	if (GEngine)
	{
		FString Message = FString::Printf(TEXT("ScoreArray Num = %d, MyMax = %d"), ScoreArray.Num(), MaxValue);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, Message);
	}

	// =====================================================
	// TMapの基礎：Add上書き / Find / FindOrAdd
	// =====================================================

	// 同じキーに対してAddを2回呼んでいる -> 例外にならず黒上書きされる
	// （C#のDictionary.Addは重複キーでArgumentExceptionを投げるが、TMapは投げない）
	ItemNameCache.Add(1, TEXT("book"));
	ItemNameCache.Add(1, TEXT("text"));

	// Findの戻り値はFString*（ポインタ）。キーが無ければnullptr。
	// 中身を見る前に必ずnullptrチェックが必要。
	FString* FoundPtr = ItemNameCache.Find(1);
	if (FoundPtr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Find(1) = %s"), **FoundPtr);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Find(1) = NULL"));
	}

	// FindOrAddの戻り値はFString&（参照）。TMap内の実データそのものを指す。
	// キーが無ければデフォルト値で新規追加してからその参照を返す。
	// 参照に代入すると、TMap内部のデータが直接書き換わる。
	FString& Ref = ItemNameCache.FindOrAdd(2);
	Ref = TEXT("Something");

	FString* FoundPtr2 = ItemNameCache.Find(2);
	if (FoundPtr2)
	{
		UE_LOG(LogTemp, Warning, TEXT("After FindOrAdd, Find(2) = %s"), **FoundPtr2);
	}

	// =====================================================
	// 独自キー型の検証：FItemKey + operator== + GetTypeHash
	// =====================================================

	// 内容は同じだが、別々に作った2つのインスタンス
	FItemKey Key1;
	Key1.ItemType = TEXT("Sword");
	Key1.Rarity = 3;

	FItemKey Key2;
	Key2.ItemType = TEXT("Sword");
	Key2.Rarity = 3;

	// 内容が同じなら、GetTypeHashは同じ値を返すはず
	uint32 HashValue1 = GetTypeHash(Key1);
	uint32 HashValue2 = GetTypeHash(Key2);
	UE_LOG(LogTemp, Warning, TEXT("FItemKey Hash (Key1) = %u"), HashValue1);
	UE_LOG(LogTemp, Warning, TEXT("FItemKey Hash (Key2) = %u"), HashValue2);

	// Key1でAddして、Key2（別インスタンス・同内容）でFindする。
	// これが成功すれば、operator==とGetTypeHashが正しく連携している証拠になる
	// （TMapがKey1とKey2を「同じキー」として扱えている）。
	TMap<FItemKey, FString> KeyTestMap;
	KeyTestMap.Add(Key1, TEXT("Excalibur"));

	FString* KeyTestResult = KeyTestMap.Find(Key2);
	if (KeyTestResult)
	{
		UE_LOG(LogTemp, Warning, TEXT("Found via Key2: %s"), **KeyTestResult);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Key2 lookup failed"));
	}
}

// Called every frame
void ABridgeLearningActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}