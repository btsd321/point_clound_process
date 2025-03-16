#ifndef TRANSLATION_H
#define TRANSLATION_H

#include <QObject>
#include "common/DataType.h"

namespace btsd
{
    typedef enum ENUM_LANGUAGE_TYPE
    {
        EM_LANGUAGE_TYPE_ENGLISH = 0,
        EM_LANGUAGE_TYPE_CHINESE,
        EM_LANGUAGE_TYPE_MAX
    }EM_LANGUAGE_TYPE;

    class CTranslation : public QObject
    {
        Q_OBJECT
    private:
        static BOOL m_b_initflag;
        static EM_LANGUAGE_TYPE m_emLanguageType;
    
    public:
        static CTranslation* Instance();
        static EM_LANGUAGE_TYPE GetCurLanguageType();
        static void Init();
        static void ChangeLanguage(EM_LANGUAGE_TYPE emLanguageType);
    signals:
        void signal_change_language();
    };
}

#endif // TRANSLATION_H
