#ifndef CLOUD_CONVERTER_H
#define CLOUD_CONVERTER_H

namespace btsd
{
    class CCloudConverter
    {
    public:
        CCloudConverter();
        ~CCloudConverter();
        void ConvertCloud(const std::string& input_file, const std::string& output_file);
    };
}
#endif // CLOUD_CONVERTER_H