#include "RoundButton.h"

void URoundButton::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);

	MyRadioButton.Reset();
}

TSharedRef<SWidget> URoundButton::RebuildWidget()
{
	MyRadioButton = SNew(SSlateRoundButton)
	.OnRadioButtonChanged(BIND_UOBJECT_DELEGATE(FOnRadioButtonChanged, HandleRadioButtonStateChanged));

	return  MyRadioButton.ToSharedRef();
}

void URoundButton::HandleRadioButtonStateChanged(ERadioChoice NewRadioChoise)
{
	if(OnRadioButtonChanged.IsBound())
	{
		OnRadioButtonChanged.Broadcast(NewRadioChoise);
	}
}

