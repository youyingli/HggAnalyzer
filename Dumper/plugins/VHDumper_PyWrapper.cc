#include <boost/python.hpp>

#include "HggAnalyzer/Dumper/interface/ZHLeptonicDumper.h"
#include "HggAnalyzer/Dumper/interface/WHLeptonicDumper.h"
#include "HggAnalyzer/Dumper/interface/VHMetDumper.h"

using namespace boost::python;

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS( ZHLeptonicDumper_Dumper, ZHLeptonicDumper::Dumper, 1, 3);
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS( ZHLeptonicDumper_SetGlobalScale, ZHLeptonicDumper::SetGlobalScale, 0, 1);

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS( WHLeptonicDumper_Dumper, WHLeptonicDumper::Dumper, 1, 3);
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS( WHLeptonicDumper_SetGlobalScale, WHLeptonicDumper::SetGlobalScale, 0, 1);

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS( VHMetDumper_Dumper, VHMetDumper::Dumper, 1, 3);
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS( VHMetDumper_SetGlobalScale, VHMetDumper::SetGlobalScale, 0, 1);

BOOST_PYTHON_MODULE(pluginVHDumper)
{

    class_<ZHLeptonicDumper>("ZHLeptonicDumper", init<std::string,std::string>())
        .def("Dumper",         &ZHLeptonicDumper::Dumper, ZHLeptonicDumper_Dumper())
        .def("SetGlobalScale", &ZHLeptonicDumper::SetGlobalScale, ZHLeptonicDumper_SetGlobalScale())
        ;

    class_<WHLeptonicDumper>("WHLeptonicDumper", init<std::string,std::string>())
        .def("Dumper",         &WHLeptonicDumper::Dumper, WHLeptonicDumper_Dumper())
        .def("SetGlobalScale", &WHLeptonicDumper::SetGlobalScale, WHLeptonicDumper_SetGlobalScale())
        ;

    class_<VHMetDumper>("VHMetDumper", init<std::string,std::string>())
        .def("Dumper",         &VHMetDumper::Dumper, VHMetDumper_Dumper())
        .def("SetGlobalScale", &VHMetDumper::SetGlobalScale, VHMetDumper_SetGlobalScale())
        ;

}
