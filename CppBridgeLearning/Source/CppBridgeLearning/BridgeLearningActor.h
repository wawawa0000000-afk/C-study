// BridgeLearningActor.h
// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BridgeLearningActor.generated.h"

// =====================================================
// テンプレート関数（C++のジェネリクス。C#のジェネリックメソッドに近い）
// =====================================================
template<typename T>
T MyMax(T A, T B)
{
	return (A > B) ? A : B;
}

// =====================================================
// グローバル領域（クラスの外）。
// USTRUCTやGetTypeHashのようなフリー関数はここに書く。
// クラスのメンバでも、関数内のローカル変数でもない場所。
// =====================================================

USTRUCT(BlueprintType)
struct FItemKey
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FString ItemType;

	UPROPERTY(EditAnywhere)
	int32 Rarity = 0;

	// operator== はFItemKeyにとって「等しい」とは何かを定義する。
	// C#のEqualsオーバーライドと役割は同じだが、virtual/overrideではなく、
	// この型専用に==という記号の意味を新規定義しているだけ。
	bool operator==(const FItemKey& Other) const
	{
		return ItemType == Other.ItemType && Rarity == Other.Rarity;
	}
};

// GetTypeHashはクラスのメンバではなく、構造体の外で定義されたフリー関数。
// C#のGetHashCodeに相当。TMapがFItemKeyをキーとして扱う際、
// 内部でこれを呼んでどの位置（バケツ）に格納・検索するかを決める。
//
// FORCEINLINE（inline）が必要な理由：
// このヘッダは複数の.cppファイルに#includeされる
// （あなたのBridgeLearningActor.cppと、UHTが自動生成するBridgeLearningActor.gen.cppの両方）。
// inlineを付けないと、それぞれの.cppにこの関数の実体がコピーされ、
// リンカが「同じ関数が複数定義されている」とエラーを出す（LNK2005）。
// operator==はクラス定義の内側にあるため自動でinline扱いになるが、
// フリー関数は明示的にinlineを指定する必要がある。
FORCEINLINE uint32 GetTypeHash(const FItemKey& Key)
{
	// ItemTypeとRarityそれぞれをUE標準のGetTypeHash（FString版・int32版）でハッシュ化し、
	// HashCombineで1つの値にまとめる。
	// C#の (X, Y).GetHashCode() で複数フィールドを1つにまとめる発想と同じ。
	uint32 TypeHash = GetTypeHash(Key.ItemType);
	uint32 RarityHash = GetTypeHash(Key.Rarity);
	return HashCombine(TypeHash, RarityHash);
}

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDamageTakenSignature, int32, DamageAmount);

UCLASS()
class CPPBRIDGELEARNING_API ABridgeLearningActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABridgeLearningActor();

	// =====================================================
	// クラスのメンバ変数
	// =====================================================
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BridgeLearning")
	TArray<int32> ScoreArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<int32, FString> ItemNameCache;

	UPROPERTY(BlueprintAssignable)
	FOnDamageTakenSignature OnDamageTaken;

	UPROPERTY(BlueprintAssignable)
	FOnDamageTakenSignature OnHitDamageTaken;

	UFUNCTION()
	void HandleDamageTaken(int32 DamageAmount);

	UFUNCTION()
	void HitDamageTaken(int32 DamageAmount);

	// ヘッダ側
	UPROPERTY(VisibleAnywhere)
	int32 TotalDamage = 0;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};