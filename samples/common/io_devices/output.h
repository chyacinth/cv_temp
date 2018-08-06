//
// Created by chris on 18-7-20.
//

#ifndef SAMPLES_OUTPUT_H
#define SAMPLES_OUTPUT_H

#include "result.h"
#include "opencv2/opencv.hpp"

class BaseOutput {
 public:
  BaseOutput() = default;
  virtual void prepareData(const InferenceResult::FaceDetectionResult&) = 0;
  virtual void prepareData(const InferenceResult::EmotionsDetectionResult&) = 0;
  virtual void prepareData(const InferenceResult::AgeGenderResult&) = 0;
  virtual void handleOutput(const std::string &overall_output_text) = 0;
  virtual void feedFrame(const cv::Mat &frame) {}
};

class ImageWindow : public BaseOutput {
 public:
  explicit ImageWindow(const std::string &window_name) : window_name_(
      window_name) {
    cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);
  }
  void prepareData(const InferenceResult::FaceDetectionResult&) override;
  void prepareData(const InferenceResult::EmotionsDetectionResult&) override;
  void prepareData(
      const InferenceResult::AgeGenderResult&) override;
  void feedFrame(const cv::Mat &) override;
  void handleOutput(const std::string &overall_output_text) override;

 private:
  const std::string window_name_;
  cv::Mat frame_;
};

#endif //SAMPLES_OUTPUT_H