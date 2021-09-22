/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/**
*/
class JuceOscillatorAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    JuceOscillatorAudioProcessor();
    ~JuceOscillatorAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    float mFreq{220};
    float mGain{0.5};

private:
//    juce::dsp::Oscillator<float> osc { [](float x) {return std::sin (x);}};
//    juce::dsp::Oscillator<float> osc { [](float x) {return x/juce::MathConstants<float>::pi; }};
    juce::dsp::Oscillator<float> osc { [](float x) {return x<0.0f ? -1.0f : 1.0f;}, 200};
    
    // Different kind of waveforms:
    // return std::sin (x); // Sine
    // return x/juce::MathConstants<float>::pi; // Saw
    // return x<0.0f ? -1.0f : 1.0f; // Square
    
    juce::dsp::Gain<float> gain;
    
    juce::Slider frequencySlider;
    juce::Label frequencyLabel;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JuceOscillatorAudioProcessor)
};
