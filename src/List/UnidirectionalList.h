/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#ifndef LIST_UNIDIRECTIONALLIST_H
#define LIST_UNIDIRECTIONALLIST_H

#include <cstdlib>

#include "AbstractList.h"
#include "Item/UnidirectionalItem.h"

namespace List {
    using namespace Item;
    
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
            void append(T itemValue)
            {
                UnidirectionalItem<T>* item;
                item = new UnidirectionalItem<T>(itemValue);
                this->end()->bindNext(item);
            }

            /**
             * @param T itemValue
             * @return void
             */
            void prepend(T itemValue)
            {
                UnidirectionalItem<T> *item;
                item = new UnidirectionalItem<T>(itemValue);
                
                item->bindNext(this->first);
                this->first = item;
            }

            /**
             * @return int
             */
            int count()
            {
                int c = 1;
                UnidirectionalItem<T>* current;
                current = this->first;

                while(current = current->getNext()) ++c;

                return c;
            }

            /**
             * @return T
             * @throws char static*
             */
            T shift()
            {
                T value = this->first->getValue();
                UnidirectionalItem<T>* shifted = this->first;

                if (NULL == this->first->getNext()) throw "List cannot be empty";

                this->first = this->first->getNext();
                delete shifted;

                return value;
            }

            /**
             * @return T
             */
            T pop()
            {
                UnidirectionalItem<T> *current;
                T value;

                if (NULL == this->first->getNext()) throw "List cannot be empty";

                current = this->first;
                while (current->getNext()->getNext()) {
                    current = current->getNext();
                }

                value = current->getNext()->getValue();

                delete current->getNext();
                current->bindNext(NULL);

                return value;
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
