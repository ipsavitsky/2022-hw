#include "symb_math/functions_factory.hpp"

template <class cur_obj>
std::unique_ptr<function> functions_factory::creator<cur_obj>::create(
    std::initializer_list<double> init_vals) const {
    return std::make_unique<cur_obj>(init_vals);
}

template <typename T>
void functions_factory::register_creator(const std::string& name) {
    registered_creators[name] = std::make_shared<creator<T>>();
}

void functions_factory::register_all() {
    register_creator<ident>("ident");
    register_creator<_const>("const");
    register_creator<power>("power");
    register_creator<exponent>("exponent");
    register_creator<polynom>("polynom");
}

functions_factory::functions_factory() {
    register_all();
}

std::unique_ptr<function> functions_factory::create_object(
    const std::string& name,
    std::initializer_list<double> init_vals) const {
    auto cr = registered_creators.find(name);
    return cr == registered_creators.end() ? nullptr
                                           : cr->second->create(init_vals);
}