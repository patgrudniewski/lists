/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#ifndef LIST_ITEM_ABSTRACTITEM_H
#define LIST_ITEM_ABSTRACTITEM_H

namespace List::Item {
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
}

#endif
