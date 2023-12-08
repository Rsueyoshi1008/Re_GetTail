// Fill out your copyright notice in the Description page of Project Settings.


#include "Stage_Scene_Component.h"
#include "Math\RandomStream.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include <random>
#include <chrono>

int characterNum = 4; //操作するPlayerの人数（恐怖のマジックナンバー）

// Sets default values for this component's properties
UStage_Scene_Component::UStage_Scene_Component()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UStage_Scene_Component::BeginPlay()
{
	Super::BeginPlay();
	// 現在の時刻を取得してシードとして使用する
	unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());

	std::mt19937 gen(seed); // メルセンヌ・ツイスター・エンジンを使用（MT19937）

	// 乱数分布を作成
	std::uniform_int_distribution<> distribution(0, 3);

	// 1から4までのランダムな整数を生成
	int randomNumber = distribution(gen);

	// TArrayでプレイヤーキャラクターを格納する変数を宣言
	TArray<ACharacter*> PlayerCharacters;

	// 新しいプレイヤーキャラクターを取得（生成した乱数の要素取得）
	ACharacter* NewPlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), randomNumber);

	// TArrayに新しいプレイヤーキャラクターを追加
	PlayerCharacters.Add(NewPlayerCharacter);

	// プレイヤーキャラクターにアタッチされた StaticMeshComponent を取得する（例として MeshComponent という名前のものを取得する場合）
	UStaticMeshComponent* MeshComponent = nullptr;

	// TArrayからプレイヤーキャラクターを取得し、処理を行う例
	for (UActorComponent* ActorComponent : PlayerCharacters->GetComponents())
	{
		// 球のマテリアルを取得する
		UMaterialInterface* Material = MeshComponent->GetMaterial(0);
		// PlayerCharacterがnullptrでない場合（有効なオブジェクトを指している場合）
		if (PlayerCharacter)
		{
			// プレイヤーキャラクターが存在する場合の処理

		}
		else
		{
			// プレイヤーキャラクターが存在しない場合の処理
		}
	}
	
	
	
}


// Called every frame
void UStage_Scene_Component::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


