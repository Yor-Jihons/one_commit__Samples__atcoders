/**
* @file
* @brief To compare the expected values and actual values.
*/

#ifndef COMPARISION_COMPARER_H
#define COMPARISION_COMPARER_H

#include<vector>
#include<string>

namespace Testor::Comparision{
    /** @brief The class in order to compare the expected values and actual values. */
    class VectorComparer{
        public:
            /**
            * @brief Constructor.
            * @param allow2ShowMessage_WhenError Whether error message will be shown when the error raised.
            */
            VectorComparer( bool allow2ShowMessage_WhenError );

            /**
            * @brief Destructor.
            */
            ~VectorComparer() = default;

            /**
            * @brief Constructor.
            * @param expected The expected values.
            * @param actuals The actual values.
            */
            bool Compare( const std::vector<std::string>& expected, const std::vector<std::string>& actuals );
        private:
            /// @brief Whether error message will be shown when the error raised.
            bool allow2ShowMessage_WhenError_;
    };
}

#endif
