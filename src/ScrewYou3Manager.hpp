#include "./generated/functions.hpp"

class ScrewYou3Manager {
    private:
        ScrewYou3Manager() {}

        /**
         * A vector determining the classes that didn't get 'killed' yet
         */
        ScrewYouFuncsT m_survivingClasses = getFuncs();

    public:
        static ScrewYou3Manager* get();

        ScrewYouFuncsT getSurvivingFuncs();

        /// Check if a function got killed. Formatted as `Class::func`
        bool isKilled(std::string funcPath);
        bool isKilled(std::string clazz, std::string funcName);

        /// Kills a function formatted as `Class::func`
        void killClass(std::string funcPath);
        void killClass(std::string clazz, std::string funcName);
        void killRandomClass();
};