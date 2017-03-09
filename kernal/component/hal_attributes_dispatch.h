#ifndef Halberd_Kernal_Component_Hal_Attributes_Dispatch_H_
#define Halberd_Kernal_Component_Hal_Attributes_Dispatch_H_

#include <base/hal_inct.h>

#define __hal_attributes_define(_class)                                         \
    class hal_attributes_dispatch##_class final {                               \
    friend class _class;                                                        \
    using __attr_host_class = _class;                                           \
    typedef void (_class::*cFunc_t)(const char*);                               \
    typedef std::map<std::string, cFunc_t> map_funtion_pool_t;                  \
    private:                                                                    \
        bool dispath(std::string& k, const char* val, _class* that) {           \
            if ("" == k || nullptr == val || nullptr == that) {                 \
                return false;                                                   \
            }                                                                   \
            map_funtion_pool_t::iterator _it = map_funtion_pool_.find(k);       \
            if (map_funtion_pool_.end() == _it) {                               \
                return false;                                                   \
            }                                                                   \
            if (nullptr != _it->second) {                                       \
                (that->*(_it->second))(val);                                    \
            }                                                                   \
            return true;                                                        \
        }                                                                       \
    private:                                                                    \
        map_funtion_pool_t map_funtion_pool_;                                   \
    public:                                                                     \
        static hal_attributes_dispatch##_class& share_instance() {              \
            static hal_attributes_dispatch##_class _instance;                   \
            return _instance;                                                   \
        }                                                                       \
        hal_attributes_dispatch##_class() {

#define __hal_attributes_map(name, func)                                        \
    map_funtion_pool_[#name] = &__attr_host_class::func;

#define __hal_attributes_define_end()                                           \
        }                                                                       \
    };

#define __hal_attributes_class                                                  \
    hal_attributes_dispatch##_class

#define __hal_attributes_dispatch(_class)                                       \
    hal_attributes_dispatch##_class::share_instance()

#endif//Halberd_Kernal_Component_Hal_Attributes_Dispatch_H_
