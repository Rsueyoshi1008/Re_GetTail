// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"

#include "UTimeTextUI.generated.h"

UCLASS()
class GETTAIL_API UTimeTextUI : public UUserWidget
{
    GENERATED_BODY()

public:
    // テキストサイズを変更する関数
    UFUNCTION(BlueprintCallable, Category = "UI")
    void ChangeTextSize(int32 NewSize);

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    UTextBlock* CountDownText;

};
