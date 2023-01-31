#ifndef YDS_TEXTURE_H
#define YDS_TEXTURE_H

#include "yds_context_object.h"

#include <string>

class ysTexture : public ysContextObject {
    friend class ysDevice;

public:
    static const int MAX_FILENAME_LENGTH = 256;

public:
    ysTexture();
    ysTexture(DeviceAPI API);
    virtual ~ysTexture();

    std::string GetFilename() const { return m_filename; }
    int GetWidth() const { return m_width; }
    int GetHeight() const { return m_height; }

protected:
    int m_width;
    int m_height;

    std::string m_filename;
};

#endif /* YDS_TEXTURE_H */
