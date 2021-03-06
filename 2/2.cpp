#include <iostream>
#include <vector>

using namespace std;

#define FB_GROUP_OOCPP "groups/2585120355118347"
#define AUTHOR "Ramojus Lapinskas"
#define PROFESSOR "Irmantas Radavicius"
#define CODE_GRAPH "[image of uml diagram]"
#define CODE_LINK "https://pastebin.com/XHxKhzfB"

class FacebookPost {
    public:
        class Reaction {
            public:
                enum Type {
                    LIKE,
                    LOVE,
                    CARE,
                    HAHA,
                    WOW,
                    SAD,
                    ANGRY
                };
            private:
                string author;
                Type type;

                void setAuthor(string newAuthor) {
                    author = newAuthor;
                }
            public:
                int create(string initAuthor, Type initType) {
                    if (author.empty()) {
                        setAuthor(initAuthor);
                        setType(initType);
                        return 0;
                    }
                    return -1;
                }
                string getAuthor() {
                    return author;
                }
                Type getType() {
                    return type;
                }
                void setType(Type newType) {
                    type = newType;
                }
        };

        class Comment {
            private:
                string author;
                string content;
                vector<Reaction> reactions;

                void setAuthor(string newAuthor) {
                    author = newAuthor;
                }
            public:
                void addReaction(Reaction newReaction) {
                    reactions.push_back(newReaction);
                }
                int create(string initAuthor, string initContent) {
                    if (author.empty()) {
                        setAuthor(initAuthor);
                        setContent(initContent);
                        return 0;
                    }
                    return -1;
                }
                string getAuthor() {
                    return author;
                }
                string getContent() {
                    return content;
                }
                vector<Reaction> getReactions() {
                    return reactions;
                }
                void setContent(string newContent) {
                    content = newContent;
                }
        };

    private:
        string author;
        vector<Comment> comments;
        string content;
        string place;
        vector<Reaction> reactions;
        string title;

        void setAuthor(string newAuthor) {
            author = newAuthor;
        }
    public:
        FacebookPost() {
        }
        ~FacebookPost() {
        }
        void addComment(Comment newComment) {
            comments.push_back(newComment);
        }
        void addReaction(Reaction newReaction) {
            reactions.push_back(newReaction);
        }
        int changeComment(Comment newComment, int index) {
            if (comments.size() > index) {
                comments[index] = newComment;
                return 0;
            }
            return -1;
        }
        int changeReaction(Reaction newReaction, int index) {
            if (reactions.size() > index) {
                reactions[index] = newReaction;
                return 0;
            }
            return -1;
        }
        int create(string initPlace, string initAuthor, string initTitle, string initContent) {
            if (author.empty()) {
                setPlace(initPlace);
                setAuthor(initAuthor);
                setTitle(initTitle);
                setContent(initContent);
                return -1;
            }
            return -2;
        }
        string getAuthor() {
            return author;
        }
        vector<Comment> getComments() {
            return comments;
        }
        string getContent() {
            return content;
        }
        string getPlace() {
            return place;
        }
        vector<Reaction> getReactions() {
            return reactions;
        }
        string getTitle() {
            return title;
        }
        int removeComment(int index) {
            if (comments.size() > index) {
                comments.erase(comments.begin() + index);
                return 0;
            }
            return -1;
        }
        int removeReaction(int index) {
            if (comments.size() > index) {
                comments.erase(comments.begin() + index);
                return 0;
            }
            return -1;
        }
        void setContent(string newContent) {
            content = newContent;
        }
        void setPlace(string newPlace) {
            place = newPlace;
        }
        void setTitle(string newTitle) {
            title = newTitle;
        }
};

int main() {
    FacebookPost post;
    post.create(
            FB_GROUP_OOCPP,
            PROFESSOR,
            "02 savaitė",
            "Mokomoji užduotis: ... "
    );

    FacebookPost::Reaction myReaction;
    myReaction.create(AUTHOR, FacebookPost::Reaction::LIKE);
    post.addReaction(myReaction);

    FacebookPost::Comment myComment;
    myComment.create(AUTHOR, CODE_GRAPH);
    post.addComment(myComment);

    FacebookPost::Reaction professorReaction;
    professorReaction.create(PROFESSOR, FacebookPost::Reaction::LOVE);
    myComment.addReaction(professorReaction);
    post.changeComment(myComment, 0);

    FacebookPost::Comment mySecondComment;
    mySecondComment.create(AUTHOR, CODE_LINK);
    post.addComment(mySecondComment);

    vector<FacebookPost> oocppGroupPosts;
    oocppGroupPosts.push_back(post);
}
