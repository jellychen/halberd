#ifndef Halberd_Base_Hal_Creator_H_
#define Halberd_Base_Hal_Creator_H_

template<class t> class hal_delete_t final {
public:
    void operator()(t* v) const {
        if (nullptr != v) {
            delete v;
        }
    }
};

template<class t> class hal_creator final {
public:
    template<class... u> static std::shared_ptr<t> instance(u&&... a) {
        auto _object = new t(std::forward<u>(a)...);
        return std::shared_ptr<t>(_object, hal_delete_t<t>{});
    }
};
#endif//Halberd_Base_Hal_Creator_H_
