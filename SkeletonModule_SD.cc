#include <bayeux/dpp/chain_module.h>
#include <bayeux/mctools/simulated_data.h>

////////////////////////////////////////////////////////////////

class SkeletonModule_SD : public dpp::chain_module
{
public:
  SkeletonModule_SD();
  ~SkeletonModule_SD();

  void initialize(const datatools::properties &, datatools::service_manager &, dpp::module_handle_dict_type &);
  dpp::chain_module::process_status process(datatools::things &);
  void finalize();
  
private:
  DPP_MODULE_REGISTRATION_INTERFACE(SkeletonModule_SD);

};

DPP_MODULE_REGISTRATION_IMPLEMENT(SkeletonModule_SD, "Skeleton_SD");

////////////////////////////////////////////////////////////////

SkeletonModule_SD::SkeletonModule_SD() : dpp::chain_module()
{

}

SkeletonModule_SD::~SkeletonModule_SD()
{
  if (this->is_initialized())
    this->finalize();
}

void SkeletonModule_SD::initialize(const datatools::properties &, datatools::service_manager &, dpp::module_handle_dict_type &)
{
  std::cout << "+++ SkeletonModule_SD::initialize()" << std::endl;
    
  this->_set_initialized(true);
}

dpp::chain_module::process_status SkeletonModule_SD::process (datatools::things &event)
{
  std::cout << "+++ SkeletonModule_SD::process()" << std::endl;

  const mctools::simulated_data & sd_bank = event.get<mctools::simulated_data>("SD");
    
  return PROCESS_OK;
  
}

void SkeletonModule_SD::finalize()
{
  std::cout << "+++ SkeletonModule_SD::finalize()" << std::endl;
  
  this->_set_initialized(false);
}
