// Fill out your copyright notice in the Description page of Project Settings.

#include "SSlateRadioButtons.h"
#include "SlateOptMacros.h"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSlateRadioButtons::Construct(const FArguments& InArgs)
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


ECheckBoxState SSlateRadioButtons::IsRadioButtonChecked(ERadioChoice RadioButtonID)
{
	return (CurrentChoice == RadioButtonID) ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
}


void SSlateRadioButtons::HandleRadioButtonStateChanged(ECheckBoxState NewRadioState, ERadioChoice RadioButtonID)
{
	if (NewRadioState == ECheckBoxState::Checked)
	{
		CurrentChoice = RadioButtonID;
		OnRadioButtonChanged.ExecuteIfBound(RadioButtonID);
	}
}

TSharedRef<SWidget> SSlateRadioButtons::CreateRadioButton(const FString& RadioText, ERadioChoice RadioButtonChoice)
{
	return SNew(SCheckBox)
	.IsChecked(MakeAttributeRaw(this, &SSlateRadioButtons::IsRadioButtonChecked,RadioButtonChoice))
	.OnCheckStateChanged(this, &SSlateRadioButtons::HandleRadioButtonStateChanged,RadioButtonChoice)
	[
		SNew(STextBlock)
		.Text(FText::FromString(RadioText))
	];
}

