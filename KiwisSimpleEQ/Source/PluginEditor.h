/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

struct CustomRotarySlider : juce::Slider
{
    CustomRotarySlider() : juce::Slider(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag,juce::Slider::TextEntryBoxPosition::NoTextBox)
    {
        
    }
};
//==============================================================================
/**
*/
class KiwisSimpleEQAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    KiwisSimpleEQAudioProcessorEditor (KiwisSimpleEQAudioProcessor&);
    ~KiwisSimpleEQAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    KiwisSimpleEQAudioProcessor& audioProcessor;

    CustomRotarySlider peakFreqSlider,
    peakGainSlider,
    peakQualitySlider,
    lowCutFreqSlider,
    highCutFreqSlider,
    lowCutSlopeSlider,
    highCutSlopeSlider;
    
    std::vector<juce::Component*> getComps();
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KiwisSimpleEQAudioProcessorEditor)
};
