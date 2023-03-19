#ifndef COMPARISION_COMPARER_H
#define COMPARISION_COMPARER_H

#include<vector>
#include<string>

namespace Testor::Comparision{
    class VectorComparer{
        public:
            VectorComparer( bool allow2ShowMessage_WhenError );
            ~VectorComparer() = default;

            bool Compare( const std::vector<std::string>& expected, const std::vector<std::string>& actuals );
        private:
            bool allow2ShowMessage_WhenError_;
    };
}

#endif
