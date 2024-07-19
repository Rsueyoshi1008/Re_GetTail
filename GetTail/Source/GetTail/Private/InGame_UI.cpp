// Fill out your copyright notice in the Description page of Project Settings.


#include "InGame_UI.h"
#include "UTimeTextUI.h"
#include "Kismet/KismetSystemLibrary.h" // 追加
#include "EnhancedInputComponent.h"
#include "InputAction.h"

// Sets default values
AInGame_UI::AInGame_UI()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInGame_UI::BeginPlay()
{
	Super::BeginPlay();



    //画面のテクストのサイズを変える処理実装途中
    if (WidgetClass != nullptr)
    {
        MyWidget = CreateWidget<UTimeTextUI>(GetWorld(), WidgetClass);
        if (MyWidget != nullptr)
        {
            UKismetSystemLibrary::PrintString(this, TEXT("ウィジェットが正常に作成され、ビューポートに追加されました。"), true, true, FColor::Cyan, 5.0f, TEXT("None"));
            MyWidget->ChangeTextSize(100); // ここでテキストサイズを変更
        }
        else
        {
			UKismetSystemLibrary::PrintString(this, TEXT("ウィジェットの作成に失敗しました。"), true, true, FColor::Red, 5.0f, TEXT("None"));
        }
    }
    else
    {
        UKismetSystemLibrary::PrintString(this, TEXT("クラスの取得に失敗"), true, true, FColor::Cyan, 5.0f, TEXT("None"));
    }
}

// Called every frame
void AInGame_UI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}




