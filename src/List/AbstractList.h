/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#ifndef LIST_ABSTRACTLIST_H
#define LIST_ABSTRACTLIST_H

namespace List {
    template<typename T>
    class AbstractList
    {
        public:
            virtual ~AbstractList() {  }

            /**
             * @param T itemValue
             * @return void
             */
            virtual void append(T itemValue) = 0;

            /**
             * @param T itemValue
             * @return void
             */
            virtual void prepend(T itemValue) = 0;

            /**
             * @return int
             */
            virtual int count() = 0;

            /**
             * @return T
             */
            virtual T shift() = 0;

            /**
             * @return T
             */
            virtual T pop() = 0;
    };
}

#endif
