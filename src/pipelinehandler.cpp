#include "pipelinehandler.h"

PipelineHandler::PipelineHandler(QObject *parent) : QObject(parent)
{

}

std::vector<std::pair<cv::Mat, Base::e_OpenCVColorFormat>> &PipelineHandler::getImagePipeline()
{
    return m_imagePipeline;
}

std::vector<std::function<void()>> &PipelineHandler::getFunctionPipeline()
{
    return m_functionPipeline;
}

std::vector<std::pair<std::vector<std::function<void()>>, QString>> &PipelineHandler::getAvailablePipelines()
{
    return m_availablePipelines;
}
                                                                    
std::function<void (cv::InputArray, cv::OutputArray, int, int)> &PipelineHandler::getCvtColor()
{
    return m_cvtColor;
                                                                    }

std::function<void (cv::InputArray, cv::OutputArray, double, double, int)> &PipelineHandler::getThreshold()
{
    return m_threshold;
}

std::function<void (cv::InputArray, cv::OutputArray, double, int, int, int, double C)> &PipelineHandler::getAdaptiveThreshold()
{
    return m_adaptiveThreshold;
}

std::function<void (cv::InputArray, cv::OutputArray, int)> &PipelineHandler::getMedianBlur()
{
    return m_medianBlur;
}

std::function<void (cv::InputArray, cv::OutputArray, cv::Size, cv::Point, int)> &PipelineHandler::getBlur()
{
    return m_blur;
}

std::function<void (cv::InputArray, cv::OutputArray, cv::Size, double, double, int)> &PipelineHandler::getGaussianBlur()
{
    return m_gaussianBlur;
}

std::function<void (cv::InputArray, cv::OutputArray, cv::InputArray)> &PipelineHandler::getBitwiseNot()
{
    return m_bitwiseNot;
}

std::function<void (cv::InputArray, double, cv::OutputArray)> &PipelineHandler::getPow()
{
    return m_pow;
}

std::function<void (cv::InputArray, cv::OutputArray, cv::InputArray, cv::Point, int, int, const cv::Scalar &)> &PipelineHandler::getErode()
{
    return m_erode;
}

std::function<void (cv::InputArray, cv::OutputArray, int, int, int, int, double, double, int)> &PipelineHandler::getSobel()
{
    return m_sobel;
}

std::function<void (cv::InputArray, cv::OutputArray, int, int, double, double, int)> &PipelineHandler::getLaplacian()
{
    return m_laplacian;
}

std::function<void (cv::InputArray, double, cv::InputArray, double, double, cv::OutputArray, int)> &PipelineHandler::getAddWeighted()
{
    return m_addWeighted;
}

std::function<void (cv::InputArray, cv::OutputArray, cv::CascadeClassifier)> &PipelineHandler::getCascadeClassifier()
{
    m_CascadeClassifier = [](cv::InputArray input, cv::OutputArray output, cv::CascadeClassifier cascade)
    {
        cv::Mat temp_gray;
        const int depth = input.depth();
        if(depth == 3)
        {
            cv::cvtColor(input, temp_gray, cv::COLOR_BGR2GRAY );
        }
        else if(depth == 1)
        {
            input.copyTo(temp_gray);
        }

        std::vector<cv::Rect> cascadeResults;
        cascade.detectMultiScale(temp_gray, cascadeResults);

        //todo draw results in input
        input.copyTo(output);

    };

    return m_CascadeClassifier;
}
