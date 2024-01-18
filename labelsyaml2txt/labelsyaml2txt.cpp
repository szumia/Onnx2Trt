#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <yaml-cpp/yaml.h>

using namespace std;

void LoadFile(string input_yaml_path, string output_txt_path)
{
    vector<string> label_values;

//    ifstream yaml_file(input_yaml_path);
//    if(!yaml_file.is_open())
//    {
//        cerr<<"ERROR: load file "<<input_yaml_path<<" failed..."<<endl;
//        exit(-1);
//    } else
//    {
//        cout<<"load file "<<input_yaml_path<<" successd..."<<endl;
//    }


    std::ofstream txt_file(output_txt_path,std::ios::app);
    if(!txt_file.is_open())
    {
        cerr<<"ERROR: open file "<<output_txt_path<<" failed..."<<endl;
        exit(-1);
    } else
    {
        cout<<"open file "<<output_txt_path<<" successd..."<<endl;
    }
    txt_file<<"std::string labels_name[]{"<<endl;

    //从"name"开始读入
    YAML::Node yaml_doc = YAML::LoadFile(input_yaml_path);
    for(YAML::const_iterator it = yaml_doc["names"].begin(); it != yaml_doc["names"].end(); ++it)
    {
        label_values.push_back(it->second.as<string>());
    }
    cout<<"size "<<label_values.size()<<endl;

    for(size_t i = 0; i < label_values.size(); i++)
    {
        txt_file<<"\"";
        txt_file<<label_values[i];
        if(i == label_values.size()-1)
        {
            txt_file<<"\"";
        } else
        {
            txt_file<<"\","<<endl;
        }
    }
    txt_file<<endl<<"};"<<endl;

//    yaml_file.close();
    txt_file.close();
}

//int main()
//{
//    string input_yaml_path,output_txt_path;
//    input_yaml_path ="/home/rp/lzt/labelsyaml2txt/coco128.yaml";
//    output_txt_path = "./coco128labels.txt";
//    cout<<"input yaml path: "<<input_yaml_path<<endl;
//    cout<<"output txt path: "<<output_txt_path<<endl;
//    LoadFile(input_yaml_path,output_txt_path);
//
//    return 0;
//
//}

int main(int argc,char** argv)
{
    string input_yaml_path,output_txt_path;
    input_yaml_path = argv[1];
    output_txt_path = argv[2];
    cout<<"input yaml path: "<<input_yaml_path<<endl;
    cout<<"output txt path: "<<output_txt_path<<endl;
    LoadFile(input_yaml_path,output_txt_path);

    return 0;

}
