#ifndef Halberd_Base_Hal_Singleton_H_
#define Halberd_Base_Hal_Singleton_H_

template<class t> class hal_singleton {
public:
    static t& share() {

        // Since it's a static variable, if the class has already been created,
        // It won't be created again.
        // And it **is** thread-safe in C++11.
        static t _instance;

        // return reference
        return _instance;
    }

    hal_singleton(hal_singleton const&) = delete;             // Copy construct
    hal_singleton(hal_singleton&&) = delete;                  // Move construct
    hal_singleton& operator=(hal_singleton const&) = delete;  // Copy assign
    hal_singleton& operator=(hal_singleton &&) = delete;      // Move assign

protected:
    hal_singleton(){

    }

    ~hal_singleton() {

    }
};
#endif//Halberd_Base_Hal_Singleton_H_
