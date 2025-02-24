/*
 * MIT License
 *
 * Copyright (c) 2020 Aaron C. Smith
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef CHIPSIE_DATABASE_HPP
#define CHIPSIE_DATABASE_HPP

#include <stdint.h>
#include <string>
#include "sqlite3.h"

class Database {
public:
    bool Init(const char *db_file);
    void AddAdmin(const std::string &admin);
    void RemAdmin(const std::string &admin);
    bool IsAdmin(const std::string &name);
    void AddCmd(const std::string &name, const std::string &response);
    void RemCmd(const std::string &name);
    bool CmdExists(const std::string &name);
    void GetCmdResp(const std::string &name, std::string *out_resp);
private:
    sqlite3 *db;

    bool TableExists(const char *table_name);
};

#endif // SAT_DATABASE_HPP