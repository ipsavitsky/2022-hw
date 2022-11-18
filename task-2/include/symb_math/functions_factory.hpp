#ifndef FUNCTIONS_FACTORY_HPP__
#define FUNCTIONS_FACTORY_HPP__

#include <initializer_list>
#include <map>
#include <memory>
#include <string>
#include "functions.hpp"

class functions_factory {
   private:
    class creator_implementation {
       public:
        virtual ~creator_implementation() {};

        virtual std::unique_ptr<function> create(
            std::initializer_list<double> init_vals) const = 0;
    };

    using creator_ptr = std::shared_ptr<creator_implementation>;

    std::map<std::string, creator_ptr> registered_creators;

    template <class cur_obj>
    class creator : public creator_implementation {
        std::unique_ptr<function> create(
            std::initializer_list<double> init_vals) const override;
    };

    template <typename T>
    void register_creator(const std::string& name);

    void register_all();

   public:
    functions_factory();

    std::unique_ptr<function> create_object(
        const std::string& name,
        std::initializer_list<double> init_vals) const;
};

#endif