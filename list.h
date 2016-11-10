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

            virtual ~AbstractItem() {  }

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
    
    template<typename T>
    class AbstractList
    {
        public:
            virtual ~AbstractList() {  }

            /**
             * @param T itemValue
             * @return void
             */
            virtual void addItem(T itemValue) = 0;
    };

    template<typename T>
    class UnidirectionalList : public AbstractList<T>
    {
        public:
            /**
             * @param UnidirectionalItem<T>* first
             */
            UnidirectionalList(UnidirectionalItem<T>* first)
                : first(first), current(first) {  }

            /**
             * @param T firstValue
             */
            UnidirectionalList(T firstValue)
            {
                this->current = new UnidirectionalItem<T>(firstValue);
            }

            /**
             * @return UnidirectionalItem<T>*
             */
            UnidirectionalItem<T>* getCurrent()
            {
                return this->current;
            }

            /**
             * @return UnidirectionalItem<T>*
             */
            UnidirectionalItem<T>* rewind()
            {
                this->current = this->first;

                return this->current;
            }

            /**
             * @return UnidirectionalItem<T>* item
             */
            UnidirectionalItem<T>* end()
            {
                UnidirectionalItem<T>* next;
                while(next = this->current->getNext()) { 
                    this->current = next;
                }

                return this->current;
            }

            /**
             * @param T itemValue
             * @return void
             */
            void addItem(T itemValue)
            {
                UnidirectionalItem<T>* item;
                item = new UnidirectionalItem<T>(itemValue);
                this->end()->bindNext(item);
            }

        private:
            /**
             * @var UnidirectionalItem<T>
             */
            UnidirectionalItem<T> *current;

            /**
             * @var UnidirectionalItem<T>
             */
            UnidirectionalItem<T> *first;
    };
}

#endif
