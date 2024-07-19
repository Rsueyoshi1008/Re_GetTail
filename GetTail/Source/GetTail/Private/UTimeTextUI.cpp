// Fill out your copyright notice in the Description page of Project Settings.


#include "UTimeTextUI.h"
#include "Kismet/KismetSystemLibrary.h"

void UTimeTextUI::ChangeTextSize(int32 NewSize)
{
    if (CountDownText != nullptr)
    {
        FSlateFontInfo FontInfo = CountDownText->Font;
        UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("フォントサイズ: %d"), FontInfo.Size), true, true, FColor::Red, 5.0f, TEXT("None"));
        FontInfo.Size = NewSize;
        CountDownText->SetFont(FontInfo);
    }
	else
	{
		UKismetSystemLibrary::PrintString(this, TEXT("テキストが見つかりません。"), true, true, FColor::Red, 5.0f, TEXT("None"));
	}
}