#ifndef BUFFERS_H
#define BUFFERS_H

class VertexBuffer
{
    private:
        unsigned int m_RendererID;
    
    public:
        VertexBuffer(const void *data, unsigned int size);
        ~VertexBuffer();

        void Bind() const;
        void Unbind() const;
};

class IndexBuffer
{
    private:
        unsigned int m_RendererID;
        unsigned int m_Count;
    
    public:
        IndexBuffer(const unsigned int *data, unsigned int count);
        ~IndexBuffer();

        void Bind() const;
        void Unbind() const;

        inline unsigned int GetCount() { return this->m_Count; }
};

#endif