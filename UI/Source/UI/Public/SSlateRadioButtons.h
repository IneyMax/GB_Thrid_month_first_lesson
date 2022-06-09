// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

DECLARE_DELEGATE_OneParam(FOnRadioButtonChanged, int32)

class UI_API SSlateRadioButtons : public SCompoundWidget
{
	
public:
	SLATE_BEGIN_ARGS(SSlateRadioButtons)
	{}
	SLATE_EVENT(FOnRadioButtonChanged, OnRadioButtonChanged)
	SLATE_END_ARGS()
	
	void Construct(const FArguments& InArgs);
	void ChangeNumberOfOptions(int32 NumberOfOptions);
	int32 GetNumberOfOptions();
	
protected:
	int32 SCurrentChoice {2};
	TAttribute<int32> SNumberOfOptions {4};
	
	FOnRadioButtonChanged SOnRadioButtonChanged;
	TSharedPtr<SVerticalBox> SMyDynamicVerticalBox;
	
protected:
	ECheckBoxState SIsRadioButtonChecked (int32 RadioButtonID);
	void SHandleRadioButtonStateChanged(ECheckBoxState NewRadioState, int32 RadioButtonID);
	TSharedRef<SWidget> SCreateRadioButton(const FString& RadioText, int32 RadioButtonChoice);
};
