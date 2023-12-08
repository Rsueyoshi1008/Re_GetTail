// Fill out your copyright notice in the Description page of Project Settings.


#include "Player_Material_CS.h"

// Sets default values for this component's properties
UPlayer_Material_CS::UPlayer_Material_CS()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayer_Material_CS::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPlayer_Material_CS::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

//マテリアルを取得する関数
UMaterialInterface* GetMaterialFromStaticMeshComponent(UStaticMeshComponent* StaticMeshComponent)
{
    if (StaticMeshComponent)
    {
        // UStaticMeshComponentからマテリアルを取得
        UMaterialInterface* Material = StaticMeshComponent->GetMaterial(0); // インデックスはマテリアルのスロット番号です（通常、0から始まります）。

        if (Material)
        {
            // マテリアルが取得できた場合の処理
            // ここに必要な処理を追加します。
            return Material;
        }
    }

    // マテリアルが見つからなかった場合はnullptrを返します。
    return nullptr;
}

// プレイヤーキャラクターのコリジョンがオブジェクトに当たった時に呼ばれる関数
void OnCollisionDetected(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    // プレイヤーキャラクターがオブジェクトに当たった時の処理
    if (OtherActor && (OtherActor != this))
    {
        // ここで色を変えるマテリアルを取得
        UMaterialInstanceDynamic* DynamicMaterial = UMaterialInstanceDynamic::Create(Player2Material, OtherComp);

        // 色を変える処理（例えば、赤色に変える場合）
        DynamicMaterial->SetVectorParameterValue(TEXT("BaseColor"), FLinearColor::Red);

        // マテリアルを設定
        OtherComp->SetMaterial(0, DynamicMaterial);
    }
}

