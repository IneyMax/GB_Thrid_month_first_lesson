// Fill out your copyright notice in the Description page of Project Settings.


#include "SSlateRoundButton.h"
#include "SlateOptMacros.h"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSlateRoundButton::Construct(const FArguments& InArgs)
{
	OnRadioButtonChanged = InArgs._OnRadioButtonChanged;
	CurrentChoice = ERadioChoice::Switch0;
	TSharedRef<SVerticalBox> MyDynamicVerticalBox = SNew(SVerticalBox);
	ChildSlot
	[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		[
			CreateRadioButton("Style 1", ERadioChoice::Switch0)
		]
		+ SVerticalBox::Slot()
		[
			CreateRadioButton("Style 2", ERadioChoice::Switch1)
		]
	];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION


ECheckBoxState SSlateRoundButton::IsRadioButtonChecked(ERadioChoice RadioButtonID)
{
	return (CurrentChoice == RadioButtonID) ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
}


void SSlateRoundButton::HandleRadioButtonStateChanged(ECheckBoxState NewRadioState, ERadioChoice RadioButtonID)
{
	if (NewRadioState == ECheckBoxState::Checked)
	{
		CurrentChoice = RadioButtonID;
		OnRadioButtonChanged.ExecuteIfBound(RadioButtonID);
	}
}

TSharedRef<SWidget> SSlateRoundButton::CreateRadioButton(const FString& RadioText, ERadioChoice RadioButtonChoice)
{
	return SNew(SCheckBox)
	.IsChecked(MakeAttributeRaw(this, &SSlateRoundButton::IsRadioButtonChecked,RadioButtonChoice))
	.OnCheckStateChanged(this, &SSlateRoundButton::HandleRadioButtonStateChanged,RadioButtonChoice)
	[
		SNew(STextBlock)
		.Text(FText::FromString(RadioText))
	];
}

