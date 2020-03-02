/**
 * @copyright Copyright (c) 2019 B-com http://www.b-com.com/
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @author Loïc Touraine
 *
 * @file
 * @brief description of file
 * @date 2019-11-15
 */

#ifndef GRPCFLATBUFFERGENERATOR_H
#define GRPCFLATBUFFERGENERATOR_H
#include <xpcf/component/ComponentBase.h>

#include "interfaces/IRPCGenerator.h"

class GRPCFlatBufferGenerator : public org::bcom::xpcf::ComponentBase, virtual public IRPCGenerator
{
public:
    GRPCFlatBufferGenerator();
    ~GRPCFlatBufferGenerator() override;
    void unloadComponent () override;
    void generate(const ClassDescriptor & c) override;

private:
    void generateMessages(const MethodDescriptor & m);

    void generateService(const ClassDescriptor & c);
};

template <> struct org::bcom::xpcf::ComponentTraits<GRPCFlatBufferGenerator>
{
    static constexpr const char * UUID = "{0DA4841C-1B2E-4A52-950C-583BD9E8BD31}";
    static constexpr const char * NAME = "GRPCFlatBufferGenerator";
    static constexpr const char * DESCRIPTION = "GRPCFlatBufferGenerator implements IRPCGenerator interface";
};

#endif // GRPCFLATBUFFERGENERATOR_H