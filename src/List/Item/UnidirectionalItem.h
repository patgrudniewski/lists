/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#ifndef LIST_ITEM_UNIDIRECTIONALITEM_H
#define LIST_ITEM_UNIDIRECTIONALITEM_H

#include <cstdlib>

#include "AbstractItem.h"

namespace List::Item {

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
