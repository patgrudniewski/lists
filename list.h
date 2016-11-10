/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#ifndef LIST_H
#define LIST_H

#include <cstdlib>

namespace list {
    template<typename T>
    class AbstractItem
    {
        public:
            /**
             * @param T value
             */
            AbstractItem(T value)
                : value(value) {  }

            virtual ~AbstractItem() {  };

            /**
             * @return T
             */
            T getValue()
            {
                return this->value;
            }
        private:
            /**
             * @var T
             */
            T value;
    };

    template<typename T>
    class UnidirectionalItem : public AbstractItem<T>
    {
        public:
            /**
             * @param T value
             */
            UnidirectionalItem(T value)
                : AbstractItem<T>(value), next(NULL) {  }

            ~UnidirectionalItem() {  }

            /**
             * @param UnidirectionalItem<T>* next
             * @return void
             */
            void bindNext(UnidirectionalItem<T>* next)
            {
                this->next = next;
            }

            /**
             * @return UnidirectionalItem<T>*
             */
            UnidirectionalItem<T>* getNext()
            {
                return this->next;
            }

        private:
            /**
             * @var UnidirectionalItem<T>*
             */
            UnidirectionalItem<T> *next;
    };
}

#endif
