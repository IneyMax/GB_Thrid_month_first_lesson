// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

UENUM(BlueprintType)
enum class ERadioChoice : uint8
{
	Switch0,
	Switch1,
	Switch2
};

DECLARE_DELEGATE_OneParam(FOnRadioButtonChanged, ERadioChoice)

class UI_API SSlateRoundButton : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSlateRoundButton)
	{}
	SLATE_EVENT(FOnRadioButtonChanged, OnRadioButtonChanged)
	SLATE_END_ARGS()
	
	void Construct(const FArguments& InArgs);
protected:
	ERadioChoice CurrentChoice;
	FOnRadioButtonChanged OnRadioButtonChanged;
	uint8 NumberOfOptions {3};
	
protected:
	ECheckBoxState IsRadioButtonChecked (ERadioChoice RadioButtonID);
	void HandleRadioButtonStateChanged(ECheckBoxState NewRadioState, ERadioChoice RadioButtonID);
	TSharedRef<SWidget> CreateRadioButton(const FString& RadioText, ERadioChoice RadioButtonChoice);
};
