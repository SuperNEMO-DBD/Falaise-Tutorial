#include <bayeux/dpp/chain_module.h>

//////////////////////////////
// Module class declaration //
//////////////////////////////

class SkeletonModule : public dpp::chain_module
{
public:

  // Constructor
  SkeletonModule();

  // Destructor
  ~SkeletonModule();

  // Initialize called before processing (inherited from dpp:chain_module)
  void initialize(const datatools::properties &, datatools::service_manager &, dpp::module_handle_dict_type &);

  // Process function for each events (inherited from dpp:chain_module
  dpp::chain_module::process_status process(datatools::things &);

  // Finalize function (costum method) called at the class destruction
  void finalize();
  
private:
  // Bayeux' macro to register this class as data processing module
  DPP_MODULE_REGISTRATION_INTERFACE(SkeletonModule);

  // Members
  unsigned long long nb_events_processed;
};

/////////////////////////////
// Module class definition //
/////////////////////////////

// Bayeux' macro to register this class as data processing module
DPP_MODULE_REGISTRATION_IMPLEMENT(SkeletonModule, "Skeleton");


SkeletonModule::SkeletonModule() : dpp::chain_module() {}

SkeletonModule::~SkeletonModule()
{
  if (this->is_initialized())
    this->finalize();
}

void SkeletonModule::initialize(const datatools::properties &, datatools::service_manager &, dpp::module_handle_dict_type &)
{
  std::cout << "+++ SkeletonModule::initialize()" << std::endl;
  
  nb_events_processed = 0;
  
  this->_set_initialized(true);
}

dpp::chain_module::process_status SkeletonModule::process (datatools::things &event)
{
  std::cout << "+++ SkeletonModule::process()" << std::endl;
  ++nb_events_processed;
  return PROCESS_OK;
  
}

void SkeletonModule::finalize()
{
  std::cout << "+++ SkeletonModule::finalize()" << std::endl;
  this->_set_initialized(false);
}
