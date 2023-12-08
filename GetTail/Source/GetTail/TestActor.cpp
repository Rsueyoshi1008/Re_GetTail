// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"
#include "Materials/MaterialInstanceDynamic.h"

// コンストラクタ内または適切なタイミングで呼ばれる関数
ATestActor::ATestActor()
{
    // メッシュコンポーネントの作成
    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));

    // ルートコンポーネントとして設定
    RootComponent = MeshComponent;

    // メッシュのアセットを読み込み（例えば、"StaticMesh'/Game/Path/To/YourMesh.YourMesh'"）
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/Path/To/YourMesh.YourMesh'"));
    if (MeshAsset.Succeeded())
    {
        MeshComponent->SetStaticMesh(MeshAsset.Object);
    }

    // マテリアルのアセットを読み込み（例えば、"MaterialInstanceConstant'/Game/Path/To/YourMaterial.YourMaterial'"）
    static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialAsset(TEXT("MaterialInstanceConstant'/Game/Path/To/YourMaterial.YourMaterial'"));
    if (MaterialAsset.Succeeded())
    {
        // MaterialInstanceDynamicの作成
        DynamicMaterialInstance = UMaterialInstanceDynamic::Create(MaterialAsset.Object, MeshComponent);

        // メッシュコンポーネントに動的マテリアルを設定
        MeshComponent->SetMaterial(0, DynamicMaterialInstance);
    }

}

// マテリアルを変更する関数
void ATestActor::ChangeMaterialColor(FLinearColor NewColor)
{
    // 動的マテリアルが存在するか確認
    if (DynamicMaterialInstance)
    {
        // マテリアルのパラメータを変更
        DynamicMaterialInstance->SetVectorParameterValue(FName("Color"), NewColor);
    }
}

// Called when the game starts or when spawned
//void ATestActor::BeginPlay()
//{
//	Super::BeginPlay();
//	
//}
//
//// Called every frame
//void ATestActor::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

